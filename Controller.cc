#include "Controller.h"
#include "RelatedCourse.h"
#include "AssistantCourse.h"

#include <iostream>
using namespace std;

//Default constructor
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

//Default destructor
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

//Sets the login menu
void Controller::setLoginMenu()  {

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

//Sets general info menu
void Controller::setGenInfoMenu(){

	// allocate new GenInfoMenu // updated
	genInfoMenu = new GenInfoMenu;
	genInfoMenu->setStudentInfo(students);
	add(*genInfoMenu);
	genInfoMenu->show_all();

	// connect signal handlers // updated
	genInfoMenu->getNext()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::genInfo_next_button_clicked));


}

//Sets the course list menu
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
	courseList->getSkip()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_skip_button_clicked));

}

//Sets the student menu
void Controller::setStudentMenu(){

	//allocate a new StudentMenu
	studentMenu = new StudentMenu();
	
	add(*studentMenu);
	studentMenu->show_all();
	
	//connnect signal handlers // UPDATED
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
	setStudentMenu();
}

void Controller::student_cancel_button_clicked(){

	if(students != 0)	students->save();
	delete(students);
	students = 0;
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
		RelatedCourse r(course);
		students->applications.getTail()->relatedCourses.pushBack(&r);
		setRelatedCourseMenu();
		return;
	} else if(type == 4)	{
		remove();
		delete(courseList);
		courseList = 0;
		AssistantCourse r(course);
		students->applications.getTail()->assistedCourses.pushBack(&r);
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
	if(type ==0 )
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
	students->applications.deleteTail();
	remove();
	delete(workMenu);
	workMenu = 0;
	setStudentMenu();
}

//Create the new application and assigns it to the student created // not updated
void Controller::createProfile(string s)	{

	Application app(s);

	if(students == 0)	{
		students = new Student();
		students->applications.pushBack(&app);
	} else	{
		students->applications.pushBack(&app);
	}
}

//Applies given info to student
void Controller::applyStudentInfo()	{ 
	students->setName(genInfoMenu->getFirstName()->get_text(), genInfoMenu->getLastName()->get_text());
	students->setStuNum(genInfoMenu->getStuNum()->get_text());
	students->setEmail(genInfoMenu->getEmail()->get_text());
	students->setMajor(genInfoMenu->getMajor()->get_text());
	students->setStanding(genInfoMenu->getYear()->get_text());
	students->setCgpa(genInfoMenu->getCgpa()->get_text());
	students->setGpa(genInfoMenu->getGpa()->get_text());
	students->applications.getTail()->setStatus("pending");
}

//Applies given info to related course
void Controller::applyRelatedCourse()	{
	students->applications.getTail()->relatedCourses.getTail()->setTerm(relMenu->getTerm()->get_active_text());
	students->applications.getTail()->relatedCourses.getTail()->setYear(relMenu->getYear()->get_text());
	students->applications.getTail()->relatedCourses.getTail()->setFinalGrade(relMenu->getFinalGrade()->get_active_text());
}

//Applies given info to ta course
void Controller::applyTACourse()	{
	students->applications.getTail()->assistedCourses.getTail()->setTerm(taMenu->getTerm()->get_active_text());
	students->applications.getTail()->assistedCourses.getTail()->setYear(taMenu->getYear()->get_text());
	students->applications.getTail()->assistedCourses.getTail()->setSupervisor(taMenu->getSupervisor()->get_text());
}

//Applies given info to work experience
void Controller::applyWorkExperience()	{
	WorkExperience work;
	students->applications.getTail()->workExperiences.pushBack(&work);
	students->applications.getTail()->workExperiences.getTail()->setTitle(workMenu->getTitle()->get_text());
	students->applications.getTail()->workExperiences.getTail()->setDuration(workMenu->getDuration()->get_active_text());
	students->applications.getTail()->workExperiences.getTail()->setDuties(workMenu->getDutiesText());	
	students->applications.getTail()->workExperiences.getTail()->setStart(workMenu->getStartDate());
	students->applications.getTail()->workExperiences.getTail()->setEnd(workMenu->getEndDate());
}



