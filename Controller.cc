#include "Controller.h"
#include "RelatedCourse.h"
#include "AssistantCourse.h"

#include <iostream>
using namespace std;

//Default constructor
Controller::Controller(){
		
	// create window 
	Gtk:Window window;
	studentMenu = 0;
	courseList = 0;
	loginMenu = 0;
	typeMenu = 0;
	genInfoMenu = 0;
	relMenu = 0;
	taMenu = 0;
	workMenu = 0;
	//undergrad = 0;
	setLoginMenu();
}

//Default destructor
Controller::~Controller()	{
			
	delete(studentMenu);
	delete(courseList);
	delete(loginMenu);
	delete(typeMenu);
	delete(genInfoMenu);
	delete(relMenu);
	delete(taMenu);
	delete(workMenu);
	//delete(undergrad);
}

//Sets the login menu
void Controller::setLoginMenu()  {

	// allocated new loginMenu
	loginMenu = new LoginMenu;
	add(*loginMenu);
	loginMenu->show_all();

	// connect signal handlers
	loginMenu->getStudentButton()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::login_student_button_clicked));

	loginMenu->getTeacherButton()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::login_teacher_button_clicked));	
}

//Sets student type menu
void Controller::setTypeMenu()	{

	// allocate new StudentType
	typeMenu = new StudentTypeMenu;
	add(*typeMenu);
	typeMenu->show_all();

	// connect signal handlers
	typeMenu->getUndergrad()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::typeMenu_undergrad_button_clicked));
	typeMenu->getGrad()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::typeMenu_grad_button_clicked));
}

//Sets general info menu
void Controller::setGenInfoMenu(){

	// allocate new GenInfoMenu
	genInfoMenu = new GenInfoMenu;
	//genInfoMenu->setUndergradInfo(undergrad);
	add(*genInfoMenu);
	genInfoMenu->show_all();

	// connect signal handlers
	genInfoMenu->getNext()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::genInfo_next_button_clicked));

	set_default_size(genInfoMenu->get_width(), genInfoMenu->get_height());
}

//Sets the course list menu
void Controller::setCourseListMenu(int type){
	// alllocate new CourseListMenu
	courseList = new CourseListMenu(type);
	add(*courseList);
	courseList->show_all();

	//connect signal handlers
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = courseList->getTreeView()->get_selection();
	refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::courselist_treeview_row_selected));

	courseList->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_select_button_clicked));
	courseList->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_cancel_button_clicked));
	courseList->getSkip()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_skip_button_clicked));
}

//Sets the student menu
void Controller::setStudentMenu(){

	//allocate a new StudentMenu
	studentMenu = new StudentMenu();
	
	add(*studentMenu);
	studentMenu->show_all();
	
	//connnect signal handlers
	studentMenu->getCancelButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::student_cancel_button_clicked));
	studentMenu->getCreateButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::student_create_button_clicked));
}

//Set the teacher menu
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

//Sets the ta course menu
void Controller::setTACourseMenu()	{
	taMenu = new TACourseMenu();
	add(*taMenu);
	show_all();

	taMenu->getNextButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_next_button_clicked));
	taMenu->getAddButton()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::taMenu_add_button_clicked));
}

//Sets the work experience menu
void Controller::setExperienceMenu()	{
	workMenu = new WorkExperienceMenu();
	add(*workMenu);
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
	
	remove();
	delete typeMenu;
	typeMenu = 0;
	setStudentMenu();
}

void Controller::typeMenu_grad_button_clicked()	{

	remove();
	delete typeMenu;
	typeMenu = 0;
	setStudentMenu();
}

void Controller::student_cancel_button_clicked(){

	//if(undergrad != 0)	undergrad->save();
	//delete(undergrad);
	//undergrad = 0;
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
	courseList->getSelect()->set_sensitive(true);
}

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
		remove();
		delete(courseList);
		courseList = 0;
		//undergrad->getApplications()->back()->getRelated()->pushBack(new RelatedCourse(course));
		setRelatedCourseMenu();
		return;
	} else if(type == 4)	{
		remove();
		delete(courseList);
		courseList = 0;
		//->getApplications()->back()->getAssisted()->pushBack(new AssistantCourse(course));
		setTACourseMenu();
		return;
	} else if(type == 1 ){
		courseList->findApp();
	}
}

void Controller::courselist_cancel_button_clicked(){
	int type = courseList->getType();
	remove();
	delete (courseList);
	courseList=0;
	if(type == 0 )
	setStudentMenu();
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

void Controller::genInfo_next_button_clicked(){
	if(genInfoMenu->checkInfo()){
		applyStudentInfo();
		remove();
		delete (genInfoMenu);
		genInfoMenu = 0;
		setCourseListMenu(3);
	}
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
	cout << "Seggy 1" << endl;
	//undergrad->getApplications()->deleteTail();
	cout << "Seggy 2" << endl;
	remove();
	delete(workMenu);
	workMenu = 0;
	setStudentMenu();
}

//Create the new application and assigns it to the student created // not updated
void Controller::createProfile(string s)	{

	Application* app = new Application(s);

	/*if(undergrad == 0)	{
		undergrad = new Undergrad();
		undergrad->getApplications()->pushBack(app);
	} else	{
		undergrad->getApplications()->pushBack(app);
	}*/
}

//Applies given info to student
void Controller::applyStudentInfo()	{ 
	//undergrad->setName(genInfoMenu->getFirstName()->get_text(), genInfoMenu->getLastName()->get_text());
	//undergrad->setStuNum(genInfoMenu->getStuNum()->get_text());
	//undergrad->setEmail(genInfoMenu->getEmail()->get_text());
	//undergrad->setMajor(genInfoMenu->getMajor()->get_text());
	//undergrad->setStanding(genInfoMenu->getYear()->get_text());
	//undergrad->setCgpa(genInfoMenu->getCgpa()->get_text());
	//undergrad->setGpa(genInfoMenu->getGpa()->get_text());
	//undergrad->getApplications()->back()->setStatus("pending");
}

//Applies given info to related course
void Controller::applyRelatedCourse()	{
	//undergrad->getApplications()->back()->getRelated()->back()->setTerm(relMenu->getTerm()->get_active_text());
	//undergrad->getApplications()->back()->getRelated()->back()->setYear(relMenu->getYear()->get_text());
	//undergrad->getApplications()->back()->getRelated()->back()->setFinalGrade(relMenu->getFinalGrade()->get_active_text());
}

//Applies given info to ta course
void Controller::applyTACourse()	{
	//undergrad->getApplications()->back()->getAssisted()->back()->setTerm(taMenu->getTerm()->get_active_text());
	//undergrad->getApplications()->back()->getAssisted()->back()->setYear(taMenu->getYear()->get_text());
	//undergrad->getApplications()->back()->getAssisted()->back()->setSupervisor(taMenu->getSupervisor()->get_text());
}

//Applies given info to work experience
void Controller::applyWorkExperience()	{
	//undergrad->getApplications()->back()->getExperience()->pushBack(new WorkExperience());
	//undergrad->getApplications()->back()->getExperience()->back()->setTitle(workMenu->getTitle()->get_text());
	//undergrad->getApplications()->back()->getExperience()->back()->setDuration(workMenu->getDuration()->get_active_text());
	//undergrad->getApplications()->back()->getExperience()->back()->setDuties(workMenu->getDutiesText());	
	//undergrad->getApplications()->back()->getExperience()->back()->setStart(workMenu->getStartDate());
	//undergrad->getApplications()->back()->getExperience()->back()->setEnd(workMenu->getEndDate());
}



