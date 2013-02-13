#include "Controller.h"

#include <iostream>
using namespace std;

Controller::Controller(){
		
	// create window 
	Gtk:Window window;
	set_size_request(300,400);
	studentMenu = 0;
	courseList = 0;
	loginMenu = 0;
	genInfoMenu = 0;
	relMenu = 0;
	taMenu = 0;
	workMenu = 0;
	students = 0;
	setLoginMenu();

}

Controller:: ~Controller()	{
			
	delete(studentMenu);
	delete(courseList);
	delete(loginMenu);
	delete(genInfoMenu);
	delete(relMenu);
	delete(taMenu);
	delete(workMenu);
	if(students != 0)	delete(students);
}


void Controller::setLoginMenu()  {

	students = NULL;
	// allocated new loginMenu // updated
	loginMenu = new LoginMenu;
	add(*loginMenu);
	loginMenu->show_all();

	// connect signal handlers
	loginMenu->getStudentButton()->signal_clicked().connect(sigc::mem_fun(*this,
	&Controller::login_student_button_clicked));

	loginMenu->getTeacherButton()->signal_clicked().connect(sigc::mem_fun(*this,
	&Controller::login_teacher_button_clicked));	

}

void Controller::setGenInfoMenu(){

	// allocate new GenInfoMenu // updated
	genInfoMenu = new GenInfoMenu;
	add(*genInfoMenu);
	genInfoMenu->show_all();

	// connect signal handlers // updated
	genInfoMenu->getNext()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::genInfo_next_button_clicked));


}

void Controller::setCourseListMenu(int type){
	// alllocate new CourseListMenu	 // updated
	courseList = new CourseListMenu(type);
	add(*courseList);
	courseList->show_all();

	//connect signal handlers /// NOT UPDATED
		Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = courseList->getTreeView()->get_selection();
		refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::courselist_treeview_row_selected));

		courseList->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_select_button_clicked));

		courseList->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_cancel_button_clicked));

}

void Controller::setStudentMenu(){

	//allocate a new StudentMenu
	studentMenu = new StudentMenu();
	
	add(*studentMenu);
	studentMenu->show_all();
	
	//connnect signal handlers // UPDATED
	studentMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::student_cancel_button_clicked));
	studentMenu->getCreateButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::student_create_button_clicked));
}

void Controller::setTeacherMenu(){
	//allocate a new TeacherMenu
	teacherMenu = new TeacherMenu();
	add(*teacherMenu);
	teacherMenu->show_all();

	//connect signal handlers
	teacherMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_cancel_button_clicked));

	teacherMenu->getSummaryButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_summary_button_clicked));

}

//Sets the related course menu, waiting for input
void Controller::setRelatedCourseMenu()	{
	relMenu = new RelatedCourseMenu();
	add(*relMenu);
	show_all();

	relMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::relMenu_next_button_clicked));
	relMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::relMenu_add_button_clicked));
}

void Controller::setTACourseMenu()	{
	taMenu = new TACourseMenu();
	add(*taMenu);
	show_all();


	taMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_next_button_clicked));

}

void Controller::setExperienceMenu()	{
	workMenu = new WorkExperienceMenu();
	add(*workMenu);
	show_all();

	workMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_next_button_clicked));
}

void Controller::login_teacher_button_clicked(){

	remove();
	delete (loginMenu);
	loginMenu= 0;
	setTeacherMenu();
}

void Controller::login_student_button_clicked(){

	remove();
	delete (loginMenu);
	loginMenu = 0;
	setStudentMenu();
}

//updated
void Controller::student_cancel_button_clicked(){

	delete(students);
	students=0;
	remove();
	delete (studentMenu);
	studentMenu=0;
	setLoginMenu();

}
void Controller::teacher_cancel_button_clicked(){

	remove();
	delete (teacherMenu);
	teacherMenu=0;
	setLoginMenu();

}
void Controller::teacher_summary_button_clicked(){

	remove();
	delete (teacherMenu);
	teacherMenu=0;
	setCourseListMenu(1);

}
// updated
void Controller::student_create_button_clicked(){

	remove();
	delete (studentMenu);
	studentMenu=0;
	setCourseListMenu(0);

}

// updated
void Controller::courselist_treeview_row_selected(){
	courseList->getSelect()->set_sensitive(true);
}

// updated
void Controller::courselist_select_button_clicked(){
	
	string course(courseList->getString());
	int type;
	if( (type = courseList->getType()) == 0  ){
		createProfile(course);
		remove();
		delete (courseList);
		courseList=0;
		setGenInfoMenu();
		return;
	} else if(type == 3)	{
		cout<<"courselist clicked"<<endl;
		remove();
		delete(courseList);
		courseList = 0;
		RelatedCourse r(course);
		students->applications.getTail()->relatedCourses.pushBack(r);
		setRelatedCourseMenu();
		return;
	} else if(type == 4)	{
		remove();
		delete(courseList);
		courseList = 0;
		AssistantCourse r(course);
		students->applications.getTail()->assistedCourses.pushBack(r);
		setTACourseMenu();
		return;
	} else if(type == 1 && students != 0){
		int length = students->getNumApps();
		Application app;
		for(int i =0; i<length; i++){
			bool toPush = students->applications.popFront(&app);
			if( course.compare(app.getCourse()) == 0){
				stringstream ss;
				ss<<students->getFirstName()<<" "<<students->getLastName()<<endl;
				ss<<students->getStuNum()<<" "<<students->getEmail()<<endl;
				ss<<students->getMajor()<<" "<<students->getStanding()<<endl;
				ss<<students->getCgpa()<<" "<<students->getGpa()<<endl;
				courseList->setString(ss.str());
				students->applications.pushBack(app);
				return;
			}
			if(toPush)
			students->applications.pushBack(app);
		}
	}
	courseList->setString("No application found");

}
// updated
void Controller::courselist_cancel_button_clicked(){
	int type = courseList->getType();
	remove();
	delete (courseList);
	courseList=0;
	if(type ==0 )
	setStudentMenu();
	else setTeacherMenu();

}

// updated
void Controller::genInfo_next_button_clicked(){
	if(checkStudentInfo()){
		applyInfo();
		students->save();
		remove();
		delete (genInfoMenu);
		genInfoMenu = 0;
		setCourseListMenu(3);
	}
}

void Controller::relMenu_next_button_clicked()	{
	remove();
	delete(relMenu);
	relMenu = 0;
	cout<<"problem deleting"<<endl;
	setCourseListMenu(4);
}
void Controller::taMenu_next_button_clicked()	{
	remove();
	delete(taMenu);
	taMenu = 0;
	cout<<"aslo here"<<endl;
	setExperienceMenu();
}
void Controller::workExperience_next_button_clicked(){
	remove();	
	delete(workMenu);
	workMenu=0;
	setStudentMenu();
}

void Controller::relMenu_add_button_clicked()	{
	
}

//Create the new application and assigns it to the student created // not updated
void Controller::createProfile(string s)	{

	Application app(s);

	if(students == 0)	{
		students = new Student();
		students->applications.pushBack(app);
	} else	{
		students->applications.pushBack(app);
	}
}

//Checks student info currently entered to see if valid // not updated
bool Controller::checkStudentInfo()	{
	//Variable storing boolean result
	bool result = true;
	
	//Checks first name
	if(!students->checkName(genInfoMenu->getFirstName()->get_text()))	{
		genInfoMenu->getFirstName()->set_text("");
		result = false;
	}

	//Checks last name
	if(!students->checkName(genInfoMenu->getLastName()->get_text()))	{
		genInfoMenu->getLastName()->set_text("");
		result = false;
	}

	//Checks student number
	if(!students->checkStuNum(genInfoMenu->getStuNum()->get_text()))	{
		genInfoMenu->getStuNum()->set_text("");
		result = false;
	}

	//Checks email address
	if(!students->checkEmail(genInfoMenu->getEmail()->get_text()))	{
		genInfoMenu->getEmail()->set_text("");
		result = false;
	}

	//Checks major
	if(!students->checkMajor(genInfoMenu->getMajor()->get_text()))	{
		genInfoMenu->getMajor()->set_text("");
		result = false;
	}

	//Checks year of standing
	if(!students->checkStanding(genInfoMenu->getYear()->get_text()))	{
		genInfoMenu->getYear()->set_text("");
		result = false;
	}

	//Checks cgpa value
	if(!students->checkCgpa(genInfoMenu->getCgpa()->get_text()))	{
		genInfoMenu->getCgpa()->set_text("");
		result = false;
	}

	//Checks gpa value
	if(!students->checkGpa(genInfoMenu->getGpa()->get_text()))	{
		genInfoMenu->getGpa()->set_text("");
		result = false;
	}

	//Returns result
	return result;

}

// not updated
void Controller::applyInfo()	{ 
	students->setName(genInfoMenu->getFirstName()->get_text(), genInfoMenu->getLastName()->get_text());
	students->setStuNum(genInfoMenu->getStuNum()->get_text());
	students->setEmail(genInfoMenu->getEmail()->get_text());
	students->setMajor(genInfoMenu->getMajor()->get_text());
	students->setStanding(genInfoMenu->getYear()->get_text());
	students->setCgpa(genInfoMenu->getCgpa()->get_text());
	students->setGpa(genInfoMenu->getGpa()->get_text());
	students->getApplications()->setStatus("pending");
}




