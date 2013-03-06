#include "Controller.h"
#include "RelatedCourse.h"
#include "AssistantCourse.h"

#include <iostream>
using namespace std;

//Default constructor
Controller::Controller()	{
		
	// create window 	
	studentMenu = 0;
	searchMenu= 0;
	courseList = 0;
	loginMenu = 0;
	typeMenu = 0;
	genInfoMenu = 0;
	relMenu = 0;
	taMenu = 0;
	workMenu = 0;
	undergrad = 0;
	grad = 0;
	setLoginMenu();
}

//Default destructor
Controller::~Controller()	{
	delete(searchMenu);		
	delete(studentMenu);
	delete(courseList);
	delete(loginMenu);
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
	if(type == 1){
		 searchMenu = new CourseListSearchMenu(type);
		 add(*searchMenu);
		 resize(searchMenu->getGrid()->get_width(), searchMenu->getGrid()->get_height());
		 show_all();
		 Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = searchMenu->getTreeView()->get_selection();
		 refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::courselist_treeview_row_selected));
		 searchMenu->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_select_button_clicked));
		 searchMenu->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_cancel_button_clicked));
		 searchMenu->getOptions();
		 searchMenu->getOptions()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::searchMenu_option_clicked));
	

	}
	else{ 
		courseList = new CourseListMenu(type);
		add(*courseList);
		resize(courseList->getGrid()->get_width(), courseList->getGrid()->get_height());
		show_all();

		//connect signal handlers
		Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = courseList->getTreeView()->get_selection();
		refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::courselist_treeview_row_selected));
		courseList->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_select_button_clicked));
		courseList->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_cancel_button_clicked));
		courseList->getSkip()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_skip_button_clicked));
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
}

//Set the teacher menu
void Controller::setTeacherMenu(){
	//allocate a new TeacherMenu
	teacherMenu = new TeacherMenu();
	add(*teacherMenu);
	resize(teacherMenu->getBox()->get_width(), teacherMenu->getBox()->get_height());
	show_all();

	//connect signal handlers
	teacherMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_cancel_button_clicked));
	teacherMenu->getSummaryButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::teacher_summary_button_clicked));
}

//Sets the related course menu, waiting for input
void Controller::setRelatedCourseMenu()	{
	relMenu = new RelatedCourseMenu();
	add(*relMenu);
	resize(relMenu->getGrid()->get_width(), relMenu->getGrid()->get_height());
	show_all();

	relMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::relMenu_next_button_clicked));
	relMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::relMenu_add_button_clicked));
}

//Sets the ta course menu
void Controller::setTACourseMenu()	{
	taMenu = new TACourseMenu();
	add(*taMenu);
	resize(taMenu->getGrid()->get_width(), taMenu->getGrid()->get_height());
	show_all();

	taMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_next_button_clicked));
	taMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_add_button_clicked));
}

//Sets the work experience menu
void Controller::setExperienceMenu()	{
	workMenu = new WorkExperienceMenu();
	add(*workMenu);
	resize(workMenu->getGrid()->get_width(), workMenu->getGrid()->get_height());
	show_all();

	workMenu->getSkipButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_skip_button_clicked));
	workMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_cancel_button_clicked));
	workMenu->getSubmitButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_submit_button_clicked));
	workMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::workExperience_add_button_clicked));
}

//Action listener functions for all menus buttons
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
	setTypeMenu();
}

void Controller::typeMenu_undergrad_button_clicked()	{
	
	undergrad = new Undergrad();
	remove();
	delete typeMenu;
	typeMenu = 0;
	setStudentMenu();
}

void Controller::typeMenu_grad_button_clicked()	{

	grad = new Grad();
	remove();
	delete typeMenu;
	typeMenu = 0;
	setStudentMenu();
}

void Controller::student_cancel_button_clicked()	{

	if(undergrad != 0 && !undergrad->getApplications()->isEmpty())	undergrad->save();
	if(grad != 0 && !grad->getApplications()->isEmpty())	grad->save();
	
	delete(undergrad);
	delete(grad);
	undergrad = 0;
	grad = 0;

	remove();
	delete (studentMenu);
	studentMenu = 0;
	setLoginMenu();
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

void Controller::student_create_button_clicked(){

	remove();
	delete (studentMenu);
	studentMenu = 0;
	setCourseListMenu(0);
}

void Controller::courselist_treeview_row_selected(){
	if(searchMenu !=0 ){
		searchMenu->getSelect()->set_sensitive(true);
		return;
	}
	courseList->getSelect()->set_sensitive(true);
}

void Controller::courselist_select_button_clicked(){
	
	if(searchMenu != 0){
		searchMenu->findApp();
		return;		
	}
	string course(courseList->getString());
	int type;
	if((type = courseList->getType()) == 0){
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
		if(undergrad != 0)	undergrad->getApplications()->back()->getRelated()->pushBack(new RelatedCourse(course));
		if(grad != 0)		grad->getApplications()->back()->getRelated()->pushBack(new RelatedCourse(course));
		setRelatedCourseMenu();
		return;
	} else if(type == 4)	{
		remove();
		delete(courseList);
		courseList = 0;
		if(undergrad != 0)	undergrad->getApplications()->back()->getAssisted()->pushBack(new AssistantCourse(course));
		if(grad != 0)		grad->getApplications()->back()->getAssisted()->pushBack(new AssistantCourse(course));
		setTACourseMenu();
		return;
	} 
}
void Controller::searchMenu_option_clicked(){
	searchMenu->checked();

}

void Controller::courselist_cancel_button_clicked(){
	if(searchMenu != 0){
		remove();
		delete(searchMenu);
		searchMenu=0;
		setTeacherMenu();
		return;
	}
	int type = courseList->getType();
	remove();
	delete (courseList);
	courseList = 0;
	if(type == 0)	setStudentMenu();
	else setTeacherMenu();
}

void Controller::courselist_skip_button_clicked()	{
	int type(courseList->getType());
	if(type == 3)	{
		remove();
		delete(courseList);
		courseList = 0;
		setCourseListMenu(4);
	} else if(type == 4)	{
		remove();
		delete(courseList);
		courseList = 0;
		setExperienceMenu();
	}
}

void Controller::genInfo_next_button_clicked()	{
	if(undergrad != 0 && !genInfoMenu->checkInfo("Undergrad"))	return;
	if(grad != 0 && !genInfoMenu->checkInfo("Grad"))	return;

	applyStudentInfo();
	remove();
	delete (genInfoMenu);
	genInfoMenu = 0;
	setCourseListMenu(3);
}

void Controller::relMenu_next_button_clicked()	{
	if(relMenu->checkInput())	{
		applyRelatedCourse();	
		remove();
		delete(relMenu);
		relMenu = 0;
		setCourseListMenu(4);
	}
}
void Controller::taMenu_next_button_clicked()	{
	if(taMenu->checkInput())	{
		applyTACourse();	
		remove();
		delete(taMenu);
		taMenu = 0;
		setExperienceMenu();
	}
}
void Controller::workExperience_submit_button_clicked(){
	if(workMenu->checkInput())	{
		applyWorkExperience();	
		remove();	
		delete(workMenu);
		workMenu=0;
		setStudentMenu();
	}
}

void Controller::relMenu_add_button_clicked()	{
	if(relMenu->checkInput())	{
		applyRelatedCourse();		
		remove();
		delete(relMenu);
		relMenu = 0;
		setCourseListMenu(3);
	}
}

void Controller::taMenu_add_button_clicked()	{
	if(taMenu->checkInput())	{
		applyTACourse();	
		remove();
		delete(taMenu);
		taMenu = 0;
		setCourseListMenu(4);
	}
}

void Controller::workExperience_add_button_clicked()	{
	if(workMenu->checkInput())	{
		applyWorkExperience();
		remove();
		delete(workMenu);
		workMenu = 0;
		setExperienceMenu();
	}
}

void Controller::workExperience_skip_button_clicked()	{
	remove();
	delete(workMenu);
	workMenu = 0;
	setStudentMenu();
}

void Controller::workExperience_cancel_button_clicked()	{
	
	//Delete application
	if(undergrad != 0)	undergrad->getApplications()->deleteTail();
	if(grad != 0)		grad->getApplications()->deleteTail();

	remove();
	delete(workMenu);
	workMenu = 0;
	setStudentMenu();
}

//Create the new application and assigns it to the student created // not updated
void Controller::createProfile(string s)	{

	Application* app = new Application(s);
	if(undergrad != 0)	undergrad->getApplications()->pushBack(app);
	if(grad != 0)		grad->getApplications()->pushBack(app);
}

//Applies given info to student
void Controller::applyStudentInfo()	{ 
	if(undergrad != 0)	{
		undergrad->setName(genInfoMenu->getFirstName()->get_text(), genInfoMenu->getLastName()->get_text());
		undergrad->setStuNum(genInfoMenu->getStuNum()->get_text());
		undergrad->setEmail(genInfoMenu->getEmail()->get_text());
		undergrad->setMajor(genInfoMenu->getMajor()->get_text());
		undergrad->setStanding(genInfoMenu->getYear()->get_text());
		undergrad->setCgpa(genInfoMenu->getCgpa()->get_text());
		undergrad->setGpa(genInfoMenu->getGpa()->get_text());
		undergrad->getApplications()->back()->setStatus("pending");
	}

	if(grad != 0)	{
		grad->setName(genInfoMenu->getFirstName()->get_text(), genInfoMenu->getLastName()->get_text());
		grad->setStuNum(genInfoMenu->getStuNum()->get_text());
		grad->setEmail(genInfoMenu->getEmail()->get_text());
		grad->setResearch(genInfoMenu->getResearch()->get_active_text());
		grad->setProgram(genInfoMenu->getProgram()->get_active_text());
		grad->setSupervisor(genInfoMenu->getSupervisor()->get_text());
		grad->getApplications()->back()->setStatus("pending");
	}
	
}

//Applies given info to related course
void Controller::applyRelatedCourse()	{

	if(undergrad != 0)	{
		undergrad->getApplications()->back()->getRelated()->back()->setTerm(relMenu->getTerm()->get_active_text());
		undergrad->getApplications()->back()->getRelated()->back()->setYear(relMenu->getYear()->get_text());
		undergrad->getApplications()->back()->getRelated()->back()->setFinalGrade(relMenu->getFinalGrade()->get_active_text());
	}

	if(grad != 0)	{
		grad->getApplications()->back()->getRelated()->back()->setTerm(relMenu->getTerm()->get_active_text());
		grad->getApplications()->back()->getRelated()->back()->setYear(relMenu->getYear()->get_text());
		grad->getApplications()->back()->getRelated()->back()->setFinalGrade(relMenu->getFinalGrade()->get_active_text());
	}
}

//Applies given info to ta course
void Controller::applyTACourse()	{
	
	if(undergrad != 0)	{
		undergrad->getApplications()->back()->getAssisted()->back()->setTerm(taMenu->getTerm()->get_active_text());
		undergrad->getApplications()->back()->getAssisted()->back()->setYear(taMenu->getYear()->get_text());
		undergrad->getApplications()->back()->getAssisted()->back()->setSupervisor(taMenu->getSupervisor()->get_text());
	}

	if(grad != 0)	{
		grad->getApplications()->back()->getAssisted()->back()->setTerm(taMenu->getTerm()->get_active_text());
		grad->getApplications()->back()->getAssisted()->back()->setYear(taMenu->getYear()->get_text());
		grad->getApplications()->back()->getAssisted()->back()->setSupervisor(taMenu->getSupervisor()->get_text());
	}
}

//Applies given info to work experience
void Controller::applyWorkExperience()	{
	if(undergrad != 0)	{
		undergrad->getApplications()->back()->getExperience()->pushBack(new WorkExperience());
		undergrad->getApplications()->back()->getExperience()->back()->setTitle(workMenu->getTitle()->get_text());
		undergrad->getApplications()->back()->getExperience()->back()->setDuration(workMenu->getDuration()->get_active_text());
		undergrad->getApplications()->back()->getExperience()->back()->setDuties(workMenu->getDutiesText());	
		undergrad->getApplications()->back()->getExperience()->back()->setStart(workMenu->getStartDate());
		undergrad->getApplications()->back()->getExperience()->back()->setEnd(workMenu->getEndDate());
	}

	if(grad != 0)	{
		grad->getApplications()->back()->getExperience()->pushBack(new WorkExperience());
		grad->getApplications()->back()->getExperience()->back()->setTitle(workMenu->getTitle()->get_text());
		grad->getApplications()->back()->getExperience()->back()->setDuration(workMenu->getDuration()->get_active_text());
		grad->getApplications()->back()->getExperience()->back()->setDuties(workMenu->getDutiesText());	
		grad->getApplications()->back()->getExperience()->back()->setStart(workMenu->getStartDate());
		grad->getApplications()->back()->getExperience()->back()->setEnd(workMenu->getEndDate());
	}
}



