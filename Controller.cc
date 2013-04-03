#include "Controller.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Default constructor
Controller::Controller()	{
		
	// create window
	loginID = "";
	currApp = 0;
	editing = false;
	studentMenu = 0;
	allAppsMenu = 0;
	searchMenu= 0;
	courseList = 0;
	loginMenu = 0;
	verifyMenu = 0;
	typeMenu = 0;
	genInfoMenu = 0;
	relMenu = 0;
	taMenu = 0;
	workMenu = 0;
	undergrad = 0;
	grad = 0;
	appList = 0;
	setLoginMenu();
}

//Default destructor
Controller::~Controller()	{
	delete(searchMenu);		
	delete(studentMenu);
	delete(courseList);
	delete(loginMenu);
	delete(verifyMenu);
	delete(typeMenu);
	delete(genInfoMenu);
	delete(relMenu);
	delete(taMenu);
	delete(workMenu);
	delete(undergrad);
	delete(grad);
}

//Sets the login menu
void Controller::setLoginMenu()  {
	// allocated new loginMenu
	loginMenu = new LoginMenu;
	add(*loginMenu);
	resize(loginMenu->getBox()->get_width(), loginMenu->getBox()->get_height());
	show_all();
	// connect signal handlers
	loginMenu->getStudentButton()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::login_student_button_clicked));
	loginMenu->getTeacherButton()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::login_teacher_button_clicked));
	
}


//Sets verify menu
void Controller::setVerifyMenu()	{

	//Allocate new menu
	verifyMenu = new VerificationMenu();
	add(*verifyMenu);
	resize(verifyMenu->getBox()->get_width(), verifyMenu->getBox()->get_height());
	show_all();

	//Connect signal handlers
	verifyMenu->getSubmit()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::verify_submit_button_clicked));
}

//Sets student type menu
void Controller::setTypeMenu()	{

	// allocate new StudentType
	typeMenu = new StudentTypeMenu;
	add(*typeMenu);
	resize(typeMenu->getBox()->get_width(), typeMenu->getBox()->get_height());
	show_all();

	// connect signal handlers
	typeMenu->getUndergrad()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::typeMenu_undergrad_button_clicked));
	typeMenu->getGrad()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::typeMenu_grad_button_clicked));
}

void Controller:: setAllAppsMenu(){
	allAppsMenu = new AllAppsMenu();
	add(*allAppsMenu);
	resize(allAppsMenu->getGrid()->get_width(), allAppsMenu->getGrid()->get_height());
	show_all();

	allAppsMenu->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::allApps_cancel_button_clicked));
	allAppsMenu->getSearch()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::allApps_search_button_cliked));
	allAppsMenu->getNext()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::allApps_next_button_cliked));
	allAppsMenu->getPrevious()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::allApps_prev_button_cliked));
	allAppsMenu->getName()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::allApps_clear));
	allAppsMenu->getAppNum()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::allApps_clear));
	allAppsMenu->getStuNum()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::allApps_clear));
}
//Sets general info menu
void Controller::setGenInfoMenu()	{

	// allocate new GenInfoMenu
	if(undergrad != 0)	{
		genInfoMenu = new GenInfoMenu("Undergrad");
		genInfoMenu->setUndergradInfo(undergrad);
	}
	if(grad != 0)	{		
		genInfoMenu = new GenInfoMenu("Grad");
		genInfoMenu->setGradInfo(grad);
	}

	add(*genInfoMenu);
	resize(genInfoMenu->getGrid()->get_width(), genInfoMenu->getGrid()->get_height());
	show_all();

	// connect signal handlers
	genInfoMenu->getNext()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::genInfo_next_button_clicked));
}
//Sets the course list menu
void Controller::setCourseListMenu(int type){
	// alllocate new CourseListMenu
	if(type == 1 || type == 2)	{
	 	searchMenu = new CourseListSearchMenu(type);
		searchMenu->loadCourseList();
		add(*searchMenu);
		resize(searchMenu->getGrid()->get_width(), searchMenu->getGrid()->get_height());
		show_all();
		Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = searchMenu->getTreeView()->get_selection();
		refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::courselist_treeview_row_selected));
		searchMenu->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_select_button_clicked));
		searchMenu->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_cancel_button_clicked));
		searchMenu->getOptions()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::searchMenu_option_clicked));
		searchMenu->getSave()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::searchMenu_saveB_clicked));
	} else { 
		courseList = new CourseListMenu(type);
		if(type == 111)	{
			if(undergrad != 0)	courseList->loadApplications(*undergrad, "pending");
			if(grad != 0)		courseList->loadApplications(*grad, "pending");
		} else if(type == 222)		courseList->loadWorkExperience(*currApp);
		else				courseList->loadCourseList();
		add(*courseList);
		resize(courseList->getGrid()->get_width(), courseList->getGrid()->get_height());
		show_all();

		//connect signal handlers
		Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = courseList->getTreeView()->get_selection();
		refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::courselist_treeview_row_selected));
		courseList->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_select_button_clicked));
		courseList->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_cancel_button_clicked));
		courseList->getSkip()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_skip_button_clicked));
		if(type == 222)	{
			courseList->getAdd()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_add_button_clicked));
			courseList->getSave()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_save_button_clicked));
			courseList->getDiscard()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_discard_button_clicked));
		}
	}
}

//Sets the student menu
void Controller::setStudentMenu(){

	//allocate a new StudentMenu
	studentMenu = new StudentMenu();
	
	add(*studentMenu);
	resize(studentMenu->getBox()->get_width(), studentMenu->getBox()->get_height());
	show_all();
	
	//connnect signal handlers
	studentMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::student_cancel_button_clicked));
	studentMenu->getCreateButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::student_create_button_clicked));
	studentMenu->getEditButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::student_edit_button_clicked));	
}

//Set the teacher menu
void Controller::setAppListMenu(){
	appList = new AppListMenu();
	add(*appList);
	resize(appList->getGrid()->get_width(), appList->getGrid()->get_height());
	show_all();

	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = appList->getTreeView()->get_selection();
	refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::appList_treeeview_row_selected));
	appList->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::appList_cancel_button_clicked));
	appList->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::appList_select_button_clicked));

}
void Controller::setTeacherMenu(){
	//allocate a new TeacherMenu
	teacherMenu = new TeacherMenu();
	add(*teacherMenu);
	resize(teacherMenu->getBox()->get_width(), teacherMenu->getBox()->get_height());
	show_all();

	//connect signal handlers
	teacherMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_cancel_button_clicked));
	teacherMenu->getSummaryButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_summary_button_clicked));
	teacherMenu->getAssignedButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_viewAssigned_button_clicked));
	teacherMenu->getAppButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_viewApps_button_clicked));
	teacherMenu->getAllButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_viewAll_button_clicked));
}

//Sets the related course menu, waiting for input
void Controller::setRelatedCourseMenu(RelatedCourse *course, int type)	{
	relMenu = new RelatedCourseMenu(type);
	relMenu->loadCourse(course);
	add(*relMenu);
	resize(relMenu->getGrid()->get_width(), relMenu->getGrid()->get_height());
	show_all();

	relMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::relMenu_next_button_clicked));
	relMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::relMenu_add_button_clicked));
	relMenu->getDeleteButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::relMenu_delete_button_clicked));
}

//Sets the ta course menu
void Controller::setTACourseMenu(AssistantCourse *course, int type)	{
	taMenu = new TACourseMenu(type);
	taMenu->loadCourse(course);
	add(*taMenu);
	resize(taMenu->getGrid()->get_width(), taMenu->getGrid()->get_height());
	show_all();

	taMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_next_button_clicked));
	taMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_add_button_clicked));
	taMenu->getDeleteButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_delete_button_clicked));
}

//Sets the work experience menu
void Controller::setExperienceMenu(WorkExperience *work, int type)	{
	workMenu = new WorkExperienceMenu(type);
	workMenu->loadExperience(work);
	add(*workMenu);
	resize(workMenu->getGrid()->get_width(), workMenu->getGrid()->get_height());
	show_all();

	workMenu->getSkipButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_skip_button_clicked));
	workMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_cancel_button_clicked));
	workMenu->getSubmitButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_submit_button_clicked));
	workMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_add_button_clicked));
	workMenu->getDeleteButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_delete_button_clicked));
}

//Action listener functions for all menus buttons
void Controller::login_teacher_button_clicked()	{
	remove();
	delete (loginMenu);
	loginMenu = 0;
	setTeacherMenu();
}

void Controller::login_student_button_clicked()	{
	remove();
	delete (loginMenu);
	loginMenu = 0;
	setVerifyMenu();
}


void Controller::verify_submit_button_clicked()	{
	if(verifyMenu->checkInput())	{
		loginID = verifyMenu->getNumber()->get_text();
		if(loadStudent(verifyMenu->getNumber()->get_text()))	{
			remove();
			delete (verifyMenu);
			verifyMenu = 0;
			setStudentMenu();
		} else {
			remove();
			delete (verifyMenu);
			verifyMenu = 0;			
			setTypeMenu();
		}
	}
}

void Controller::typeMenu_undergrad_button_clicked()	{
	undergrad = new Undergrad();
	undergrad->setStuNum(loginID);
	remove();
	delete typeMenu;
	typeMenu = 0;
	setStudentMenu();
}

void Controller::typeMenu_grad_button_clicked()	{
	grad = new Grad();
	grad->setStuNum(loginID);
	remove();
	delete typeMenu;
	typeMenu = 0;
	setStudentMenu();
}

void Controller::student_cancel_button_clicked()	{
	delete(undergrad);
	delete(grad);
	undergrad = 0;
	grad = 0;
	loginID = "";

	remove();
	delete (studentMenu);
	studentMenu = 0;
	setLoginMenu();
}
void Controller::allApps_cancel_button_clicked(){
	delete(allAppsMenu);
	allAppsMenu= 0;
	remove();
	setTeacherMenu();
}

void Controller::allApps_clear(){
	allAppsMenu->clear();

}
void Controller::allApps_search_button_cliked(){
	allAppsMenu->doSearch();
}
void Controller::allApps_next_button_cliked(){
	allAppsMenu->nextClicked();
}
void Controller::allApps_prev_button_cliked(){
	allAppsMenu->prevClicked();
}

void Controller::student_create_button_clicked(){
	remove();
	delete (studentMenu);
	studentMenu = 0;
	setCourseListMenu(0);
}

void Controller::student_edit_button_clicked()	{
	remove();
	delete (studentMenu);
	studentMenu = 0;
	setCourseListMenu(111);
}

void Controller::teacher_cancel_button_clicked(){
	remove();
	delete (teacherMenu);
	teacherMenu = 0;
	setLoginMenu();
}

void Controller::teacher_summary_button_clicked(){
	remove();
	delete (teacherMenu);
	teacherMenu = 0;
	setCourseListMenu(1);
}

void Controller:: teacher_viewAssigned_button_clicked(){
	remove();
	delete (teacherMenu);
	teacherMenu = 0;
	setCourseListMenu(2);
}

void Controller:: teacher_viewApps_button_clicked(){
	remove();
	delete(teacherMenu);
	teacherMenu = 0;
	setAppListMenu();
}

void Controller:: teacher_viewAll_button_clicked(){
	remove();
	delete(teacherMenu);
	teacherMenu=0;
	setAllAppsMenu();
}

void Controller::courselist_treeview_row_selected(){
	if(searchMenu != 0 ){
		searchMenu->getSelect()->set_sensitive(true);
		return;
	}
	courseList->getSelect()->set_sensitive(true);
}

void Controller::appList_treeeview_row_selected(){
	appList->getSelect()->set_sensitive(true);
}

void Controller::appList_cancel_button_clicked(){
	remove();
	delete(appList);
	appList=0;
	setTeacherMenu();

}

void Controller::appList_select_button_clicked(){
	appList->assignApp();
	remove();
	delete(appList);
	appList=0;
	setAppListMenu();
}

void Controller::courselist_select_button_clicked()	{
	if(searchMenu != 0) {
		searchMenu->findApp();
		return;		
	}

	int type = courseList->getType();
	string course(courseList->getString());
	if(type == 0)	{
		if(undergrad != 0 && undergrad->duplicateApp(course))	{
			Gtk::MessageDialog error("IDENTICAL PENDING APPLICATION ALREADY SUBMITTED!", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false);
			error.set_secondary_text("Only one pending application for each course is allowed.");
			error.run();
			return;
		}
		if(grad != 0 && grad->duplicateApp(course))	{
			Gtk::MessageDialog error("IDENTICAL PENDING APPLICATION ALREADY SUBMITTED!", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false);
			error.set_secondary_text("Only one pending application for each course is allowed.");
			error.run();
			return;
		}
		createProfile(course);
		remove();
		delete (courseList);
		courseList = 0;
		setGenInfoMenu();
		return;
	} else if(type == 3)	{
		remove();
		delete(courseList);
		courseList = 0;
		if(currApp->duplicateRel(course))	{
			RelatedCourse *temp = currApp->findRel(course);
			myQ<RelatedCourse> *queue = currApp->getRelated();
			(*queue) -= temp;
			(*queue) + temp;
			setRelatedCourseMenu(temp, editing);
			return;
		}
		*(currApp->getRelated()) + (new RelatedCourse(course));
		setRelatedCourseMenu(0, editing);
	} else if(type == 4)	{
		remove();
		delete(courseList);
		courseList = 0;
		if(currApp->duplicateAss(course))	{
			AssistantCourse *temp = currApp->findAss(course);
			myQ<AssistantCourse> *queue = currApp->getAssisted();
			(*queue) -= temp;
			(*queue) + temp;
			setTACourseMenu(temp, editing);
			return;
		}
		*(currApp->getAssisted()) + (new AssistantCourse(course));
		setTACourseMenu(0, editing);
	} else if(type == 111)	{
		remove();
		delete(courseList);
		courseList = 0;
		editing = true;
		if(undergrad != 0)	currApp = undergrad->getApp(course);
		if(grad != 0)		currApp = grad->getApp(course);
		setGenInfoMenu();
	} else if(type == 222)	{
		remove();
		delete(courseList);
		courseList = 0;
		WorkExperience *temp = currApp->findWor(course);
		myQ<WorkExperience> *queue = currApp->getExperience();
		(*queue) -= temp;
		(*queue) + temp;
		setExperienceMenu(temp, 2);
	}
}

void Controller::courselist_save_button_clicked()	{
	saveToFile();
	currApp = 0;
	editing = false;

	remove();
	delete(courseList);
	courseList = 0;
	setStudentMenu();
}

void Controller::courselist_discard_button_clicked()	{
	string stuNum;

	currApp = 0;
	editing = false;
	
	if(undergrad != 0)	{
		stuNum = undergrad->getStuNum();
		delete undergrad;
	}
	if(grad != 0)	{
		stuNum = grad->getStuNum();
		delete grad;
	}
	
	remove();
	delete(courseList);
	courseList = 0;

	loadStudent(stuNum);
	setStudentMenu();
}

void Controller::searchMenu_option_clicked(){
	searchMenu->checked();
}

void Controller::searchMenu_saveB_clicked(){
	searchMenu->print();
}

void Controller::courselist_add_button_clicked()	{
	*(currApp->getExperience()) += (new WorkExperience());
	remove();
	delete(courseList);
	courseList = 0;
	setExperienceMenu(0, editing);
}

void Controller::courselist_cancel_button_clicked(){
	if(searchMenu != 0)	{
		remove();
		delete(searchMenu);
		searchMenu = 0;
		setTeacherMenu();
		return;
	}
	int type = courseList->getType();
	if(type == 0 || type == 111)	{
		remove();
		delete (courseList);
		courseList = 0;
		setStudentMenu();
	} else if(type == 222)	{
		-(*currApp);
		courseList->getSelect()->set_sensitive(false);
		courseList->getAdd()->set_sensitive(false);
		courseList->getCancel()->set_sensitive(false);
		courseList->getTreeView()->set_sensitive(false);
		return;
	} else	{
		remove();
		delete (courseList);
		courseList = 0;
		setTeacherMenu();
	}
}

void Controller::courselist_skip_button_clicked()	{
	int type(courseList->getType());
	remove();
	delete(courseList);
	courseList = 0;
	
	if(type == 3)			setCourseListMenu(4);
	else if(type == 4 && !editing)	setExperienceMenu(0, editing);
	else				setCourseListMenu(222);
}

void Controller::genInfo_next_button_clicked()	{
	if(undergrad != 0 && !genInfoMenu->checkInfo("Undergrad"))	return;
	if(grad != 0 && !genInfoMenu->checkInfo("Grad"))	return;

	if(undergrad != 0)	genInfoMenu->applyUnderInfo(undergrad);
	if(grad != 0)	genInfoMenu->applyGradInfo(grad);
	remove();
	delete (genInfoMenu);
	genInfoMenu = 0;

	setCourseListMenu(3);

}

void Controller::relMenu_next_button_clicked()	{
	if(relMenu->checkInput())	{
		relMenu->applyRelatedCourse(*currApp);
		remove();
		delete(relMenu);
		relMenu = 0;
		setCourseListMenu(4);
	}
}

void Controller::taMenu_next_button_clicked()	{
	if(taMenu->checkInput())	{
		taMenu->applyTACourse(*currApp);	
		remove();
		delete(taMenu);
		taMenu = 0;
		if(!editing)	setExperienceMenu(0, editing);
		else		setCourseListMenu(222);
	}
}

void Controller::workExperience_submit_button_clicked(){
	if(workMenu->checkInput())	{
		if(currApp->duplicateWor(workMenu->getTitle()->get_text()))	{
			Gtk::MessageDialog error("IDENTICAL WORK EXPERIENCE TITLE ALREADY SUBMITTED!", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false);
			error.set_secondary_text("Only different work experience titles are allowed for each application.");
			error.run();
			return;
		}
		*(currApp->getExperience()) += (new WorkExperience());
		workMenu->applyWorkExperience(*currApp);
		if(undergrad != 0)	*(undergrad->getApplications()) += currApp;
		if(grad != 0)		*(grad->getApplications()) += currApp;
		saveToFile();
		remove();	
		delete(workMenu);
		workMenu = 0;
		setStudentMenu();
	}
}

void Controller::relMenu_add_button_clicked()	{
	if(relMenu->checkInput())	{
		relMenu->applyRelatedCourse(*currApp);		
		remove();
		delete(relMenu);
		relMenu = 0;
		setCourseListMenu(3);
	}
}

void Controller::relMenu_delete_button_clicked()	{
	myQ<RelatedCourse> *queue = currApp->getRelated();

	queue->deleteTail();
	remove();
	delete(relMenu);
	relMenu = 0;
	setCourseListMenu(3);
}

void Controller::taMenu_add_button_clicked()	{
	if(taMenu->checkInput())	{
		taMenu->applyTACourse(*currApp);	
		remove();
		delete(taMenu);
		taMenu = 0;
		setCourseListMenu(4);
	}
}

void Controller::taMenu_delete_button_clicked()	{
	myQ<AssistantCourse> *queue = currApp->getAssisted();

	queue->deleteTail();
	remove();
	delete(taMenu);
	taMenu = 0;
	setCourseListMenu(4);
}

void Controller::workExperience_add_button_clicked()	{
	int type = workMenu->getType();
	if(workMenu->checkInput())	{
		if(type != 2 && currApp->duplicateWor(workMenu->getTitle()->get_text()))	{
			Gtk::MessageDialog error("IDENTICAL WORK EXPERIENCE TITLE ALREADY SUBMITTED!", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false);
			error.set_secondary_text("Only different work experience titles are allowed for each application.");
			error.run();
			return;
		}
		if(workMenu->getType() == 0)	*(currApp->getExperience()) += (new WorkExperience());
		workMenu->applyWorkExperience(*currApp);
		remove();	
		delete(workMenu);
		workMenu = 0;
		if(type == 1 || type == 2)	setCourseListMenu(222);
		else		setExperienceMenu(0, editing);
	}
}

void Controller::workExperience_delete_button_clicked()	{
	myQ<WorkExperience> *queue = currApp->getExperience();
	WorkExperience *toDelete = (*queue)[queue->length()];

	queue->deleteTail();
	delete toDelete;
	remove();
	delete(workMenu);
	workMenu = 0;
	setCourseListMenu(222);
}

void Controller::workExperience_skip_button_clicked()	{
	if(undergrad != 0)	*(undergrad->getApplications()) += currApp;
	if(grad != 0)		*(grad->getApplications()) += currApp;
	saveToFile();
	remove();	
	delete(workMenu);
	workMenu = 0;
	setStudentMenu();
}

void Controller::workExperience_cancel_button_clicked()	{
	
	//Delete application
	delete currApp;
	currApp = 0;

	remove();
	delete(workMenu);
	workMenu = 0;
	setStudentMenu();
}

//Create the new application and assigns it to the student created // not updated
void Controller::createProfile(string s)	{
	int total = findHighestAppNum();
	Application* app = new Application(s,total);
	app->setStatus("pending");
	currApp = app;
}

int Controller::findHighestAppNum()	{
	ifstream myfile("saveLog.txt");
	string line;
	string symbol;
	string appNum;
	while(getline(myfile,line)){
		istringstream toParse (line, istringstream::in);
		while(getline(toParse,symbol,'$')){
			if(symbol.compare("App") == 0){
				appNum="";
				getline(toParse,appNum,'$');
			}			
		}
	}
	int i = atoi(appNum.c_str());
	if(i == 0){
		return 	-1;
	}
	else {

		return i;
	}		
}

void Controller::saveToFile()	{
	if(undergrad != 0)	{
		removeStudentFromFile(undergrad->getStuNum());
		undergrad->save();
	}
	if(grad != 0)	{
		removeStudentFromFile(grad->getStuNum());
		grad->save();
	}
}

void Controller::removeStudentFromFile(string num)	{
	int i;	
	string deleteLine;
	string line;

	ifstream myfile("saveLog.txt");
	ofstream newfile("temp.txt");
	if(!myfile.is_open())	return;

	while(myfile.good() && getline(myfile, line))	{
		istringstream toParse (line, istringstream::in);
		string stuNum;
	        
		for(i = 0; i < 4; i++)	{
			getline(toParse, stuNum, '$');
		}

		if(stuNum == num)	deleteLine = line;
		if(deleteLine != line)	newfile << line << endl;
	}
	myfile.close();
	newfile.close();
	std::remove("saveLog.txt");
	std::rename("temp.txt", "saveLog.txt");
}

//Loads student with given student number
bool Controller::loadStudent(string num)	{
	string line;
	bool loaded = false;

	ifstream myfile("saveLog.txt");
	if(!myfile.is_open())	return false;

	while(myfile.good() && getline(myfile, line))	{
		istringstream toParse (line, istringstream::in);
		string  type, firstName, lastName, stuNum , email;
	        
		getline(toParse, type, '$');

		if(type.compare("Und") == 0)	{
			string  major, standing, cgpa, gpa;
			getline(toParse,firstName,'$');
			getline(toParse,lastName,'$');
			getline(toParse,stuNum,'$');
			getline(toParse,email,'$');
			getline(toParse,major,'$');
			getline(toParse,cgpa,'$');
			getline(toParse,gpa,'$');
			getline(toParse,standing,'$');
			if(stuNum == num)	{
				loaded = true;
				undergrad = new Undergrad(firstName, lastName, stuNum, email, major, standing, cgpa, gpa);
				loadStudentInfo(toParse, *undergrad);
			}
		} else {
			string research, program, supervisor; 
			getline(toParse,firstName,'$');
			getline(toParse,lastName,'$');
			getline(toParse,stuNum,'$');
			getline(toParse,email,'$');
			getline(toParse,research,'$');
			getline(toParse,program,'$');
			getline(toParse,supervisor,'$');
			if(stuNum == num)	{
				loaded = true;
				grad = new Grad(firstName, lastName, stuNum, email, research, program, supervisor);
				loadStudentInfo(toParse, *grad);
			}
		}
	}
	myfile.close();;
	return loaded;
}

//Loads all the information associated with the student
void Controller::loadStudentInfo(istringstream &toParse, Student &stu)	{
	string symbol;

	while(getline(toParse, symbol,'$'))	{
		if(symbol.compare("App") == 0)	{
			string appNum, status, course;
			getline(toParse, appNum, '$');
			getline(toParse, status,'$');
			getline(toParse, course,'$');
		
			stu.getApplications()->pushBack(new Application(course,-1, status, atoi(appNum.c_str())));
		}
		if(symbol.compare("Rel") == 0)	{
			string course, term, year, grade;
			getline(toParse, course, '$');
			getline(toParse, term,'$');
			getline(toParse, year,'$');
			getline(toParse, grade,'$');
		
			stu.getApplications()->back()->getRelated()->pushBack(new RelatedCourse(course, term, year, grade));
		}
		if(symbol.compare("Ass") == 0)	{
			string course, t, y, sup;
			getline(toParse, course, '$');
			getline(toParse, t,'$');
			getline(toParse, y,'$');
			getline(toParse, sup,'$');
		
			stu.getApplications()->back()->getAssisted()->pushBack(new AssistantCourse(course, t, y, sup));
		}
		if(symbol.compare("Wor") == 0)	{
			string title, duties, duration, start, end;
			getline(toParse, title, '$');
			getline(toParse, duration,'$');
			getline(toParse, start,'$');
			getline(toParse, end,'$');
			getline(toParse, duties,'$');
		
			stu.getApplications()->back()->getExperience()->pushBack(new WorkExperience(title, duties, duration, start, end));
		}
	}
}
