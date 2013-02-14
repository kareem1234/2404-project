#ifndef CONTROLLER_H
#define CONTROLLER_H

// include statements
#include "Student.h"
#include "CourseListMenu.h"
#include "StudentMenu.h"
#include "LoginMenu.h"
#include "GenInfoMenu.h"
#include "TeacherMenu.h"
#include "RelatedCourseMenu.h"
#include "TACourseMenu.h"
#include "WorkExperienceMenu.h"
#include "RelatedCourseMenu.h"
#include <iostream>
#include <sstream>
#include <string>

class Controller : public Gtk::Window 	{
	
	private:
		TeacherMenu *teacherMenu;
		StudentMenu *studentMenu;
		CourseListMenu *courseList;
		LoginMenu *loginMenu;
		GenInfoMenu *genInfoMenu;
		RelatedCourseMenu *relMenu;
		TACourseMenu *taMenu;
		WorkExperienceMenu *workMenu;
		Student *students;
		void setLoginMenu();
		void teacher_summary_button_clicked();
		void setGenInfoMenu();
		void setCourseListMenu(int type);
		void setStudentMenu();
		void setTeacherMenu();
		void setRelatedCourseMenu();
		void setTACourseMenu();	
		void setExperienceMenu();
		void login_teacher_button_clicked();
		void login_student_button_clicked();
		void teacher_cancel_button_clicked();
		void genInfo_next_button_clicked();
		void relMenu_next_button_clicked();
		void relMenu_add_button_clicked();
		void taMenu_next_button_clicked();
		void taMenu_add_button_clicked();
		void workExperience_submit_button_clicked();
		void workExperience_add_button_clicked();
		void workExperience_skip_button_clicked();
		void workExperience_cancel_button_clicked();
		void student_cancel_button_clicked();
		void student_create_button_clicked();
		void courselist_treeview_row_selected();
		void courselist_select_button_clicked();
		void courselist_cancel_button_clicked();
		void courselist_skip_button_clicked();
		void createProfile(string s);
		void applyStudentInfo();
		void applyRelatedCourse();
		void applyTACourse();
		void applyWorkExperience();

	public:
		Controller();
		~Controller();
};
#endif
