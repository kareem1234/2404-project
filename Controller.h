#ifndef CONTROLLER_H
#define CONTROLLER_H

// include statements
#include"Student.h"
#include"CourseListMenu.h"
#include"StudentMenu.h"
#include"LoginMenu.h"
#include"GenInfoMenu.h"
#include "TeacherMenu.h"
#include<iostream>
#include<sstream>
#include<string>

class Controller : public Gtk::Window 	{
	
	private:
		TeacherMenu *teacherMenu;
		StudentMenu *studentMenu;
		CourseListMenu *courseList;
		LoginMenu *loginMenu;
		GenInfoMenu *genInfoMenu;
		Student *students;
		void setLoginMenu();
		void teacher_summary_button_clicked();
		void setGenInfoMenu();
		void setCourseListMenu(int type);
		void setStudentMenu();
		void setTeacherMenu();
		void login_teacher_button_clicked();
		void login_student_button_clicked();
		void teacher_cancel_button_clicked();
		void genInfo_cancel_button_clicked();
		void student_cancel_button_clicked();
		void student_create_button_clicked();
		void courselist_treeview_row_selected();
		void courselist_select_button_clicked();
		void courselist_cancel_button_clicked();
		void genInfo_submit_button_clicked();
		void createProfile(string s);
		bool checkStudentInfo();
		void applyInfo();

	public:
		Controller();
		~Controller();
};
#endif
