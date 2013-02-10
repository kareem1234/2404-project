#include "Controller.h"

using namespace std;

Controller::Controller(){
		
	// create window 
	Gtk:Window window;
	set_size_request(300,400);
	studentMenu=0;
	courseList =0;
	loginMenu =0;
	genInfoMenu=0;
	setLoginMenu();

}

Controller:: ~Controller()	{
			
		delete(studentMenu);
		delete(courseList);
		delete(loginMenu);
		delete(genInfoMenu);
		if(students != NULL){
			delete(students);
		};
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
	genInfoMenu->getCancel()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::genInfo_cancel_button_clicked));
	genInfoMenu->getSubmit()->signal_clicked().connect(sigc::mem_fun(*this, &Controller::genInfo_submit_button_clicked));


}

void Controller::setCourseListMenu(int type){
	// alllocate new CourseListMenu	 // updated
	courseList = new CourseListMenu(type);
	add(*courseList);
	courseList->show_all();

	//connect signal handlers /// NOT UPDATED
	if(type == 0){
		Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = courseList->getTreeView()->get_selection();
		refTreeSelection->signal_changed().connect(sigc::mem_fun(*this,&Controller::courselist_treeview_row_selected));

		courseList->getSelect()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_select_button_clicked));

		courseList->getCancel()->signal_clicked().connect(sigc::mem_fun(*this,&Controller::courselist_cancel_button_clicked));
	}else if(type == 1){



	}

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
void Controller::login_teacher_button_clicked(){

	remove();
	delete (loginMenu);
	loginMenu= 0;
	setTeacherMenu();
}

void Controller::login_student_button_clicked(){

	remove();
	delete (loginMenu);
	loginMenu= 0;
	setStudentMenu();
}

void Controller::genInfo_cancel_button_clicked(){
	// delete student
	delete(students);
	students =0;

	remove();
	delete (genInfoMenu);
	genInfoMenu=0;
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
	createProfile(course);
	remove();
	delete (courseList);
	courseList=0;
	setGenInfoMenu();

}
// updated
void Controller::courselist_cancel_button_clicked(){
	
	remove();
	delete (courseList);
	courseList=0;
	setStudentMenu();

}

// updated
void Controller::genInfo_submit_button_clicked(){
	if(checkStudentInfo()){
		applyInfo();
		students->save();
		remove();
		delete (genInfoMenu);
		genInfoMenu=0;
		setStudentMenu();
	}
}

//Create the new application and assigns it to the student created // not updated
void Controller::createProfile(string s)	{

	Application *app = new Application(s);

	if(students == NULL)	{
		students = new Student(app);
	} else	{
		students->setApplication(app);
	}
}

//Checks student info currently entered to see if valid // not updated
bool Controller::checkStudentInfo()	{
	//Variable storing boolean result
	bool result = true;
	
	//Checks first name
	if(!students->checkName(genInfoMenu->getFirstName()->get_text()))	{
		genInfoMenu->getFirstName()->set_text(" ");
		result = false;
	}

	//Checks last name
	if(!students->checkName(genInfoMenu->getLastName()->get_text()))	{
		genInfoMenu->getLastName()->set_text(" ");
		result = false;
	}

	//Checks student number
	if(!students->checkStuNum(genInfoMenu->getStuNum()->get_text()))	{
		genInfoMenu->getStuNum()->set_text(" ");
		result = false;
	}

	//Checks email address
	if(!students->checkEmail(genInfoMenu->getEmail()->get_text()))	{
		genInfoMenu->getEmail()->set_text(" ");
		result = false;
	}

	//Checks major
	if(!students->checkMajor(genInfoMenu->getMajor()->get_text()))	{
		genInfoMenu->getMajor()->set_text(" ");
		result = false;
	}

	//Checks year of standing
	if(!students->checkStanding(genInfoMenu->getYear()->get_text()))	{
		genInfoMenu->getYear()->set_text(" ");
		result = false;
	}

	//Checks cgpa value
	if(!students->checkCgpa(genInfoMenu->getCgpa()->get_text()))	{
		genInfoMenu->getCgpa()->set_text(" ");
		result = false;
	}

	//Checks gpa value
	if(!students->checkGpa(genInfoMenu->getGpa()->get_text()))	{
		genInfoMenu->getGpa()->set_text(" ");
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




