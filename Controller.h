//Controller header file
#ifndef CONTROLLER_H
#define CONTROLLER_H

//Include statements
#include "CourseListMenu.h"
#include "StudentMenu.h"
#include "LoginMenu.h"
#include "VerificationMenu.h"
#include "StudentTypeMenu.h"
#include "GenInfoMenu.h"
#include "TeacherMenu.h"
#include "RelatedCourseMenu.h"
#include "TACourseMenu.h"
#include "WorkExperienceMenu.h"
#include "RelatedCourseMenu.h"
#include "Grad.h"
#include "Undergrad.h"
#include <iostream>
#include <sstream>
#include <string>
#include "CourseListSearchMenu.h"
#include "RelatedCourse.h"
#include "AssistantCourse.h"
#include "AppListMenu.h"
#include "AllAppsMenu.h"

class Controller : public Gtk::Window 	{
	//Private members
	private:
		string loginID;
		Application *currApp;
		bool editing;
		TeacherMenu *teacherMenu;
		AllAppsMenu *allAppsMenu;
		StudentMenu *studentMenu;
		AppListMenu *appList;
		CourseListMenu *courseList;
		CourseListSearchMenu *searchMenu;
		LoginMenu *loginMenu;
		VerificationMenu *verifyMenu;
		StudentTypeMenu *typeMenu;
		GenInfoMenu *genInfoMenu;
		RelatedCourseMenu *relMenu;
		TACourseMenu *taMenu;
		WorkExperienceMenu *workMenu;
		Undergrad *undergrad;
		Grad *grad;
		void setLoginMenu();
		void setVerifyMenu();
		void setTypeMenu();
		void setGenInfoMenu();
		void setCourseListMenu(int type);
		void setStudentMenu();
		void setTeacherMenu();
		void setRelatedCourseMenu(RelatedCourse*, int);
		void setTACourseMenu(AssistantCourse*, int);	
		void setExperienceMenu(WorkExperience*, int);
		void setAppListMenu();
		void login_teacher_button_clicked();
		void login_student_button_clicked();
		void verify_submit_button_clicked();
		void typeMenu_grad_button_clicked();
		void teacher_viewAll_button_clicked();
		void typeMenu_undergrad_button_clicked();
		void teacher_cancel_button_clicked();
		void teacher_summary_button_clicked();
		void teacher_viewAssigned_button_clicked();
		void teacher_viewApps_button_clicked();
		void genInfo_next_button_clicked();
		void relMenu_next_button_clicked();
		void relMenu_add_button_clicked();
		void relMenu_delete_button_clicked();
		void taMenu_next_button_clicked();
		void taMenu_add_button_clicked();
		void taMenu_delete_button_clicked();
		void workExperience_submit_button_clicked();
		void workExperience_add_button_clicked();
		void workExperience_skip_button_clicked();
		void workExperience_cancel_button_clicked();
		void workExperience_delete_button_clicked();
		void student_cancel_button_clicked();
		void student_edit_button_clicked();
		void student_create_button_clicked();
		void courselist_treeview_row_selected();
		void appList_treeeview_row_selected();
		void appList_cancel_button_clicked();
		void appList_select_button_clicked();
		void courselist_select_button_clicked();
		void courselist_cancel_button_clicked();
		void courselist_discard_button_clicked();
		void courselist_add_button_clicked();
		void courselist_skip_button_clicked();
		void courselist_save_button_clicked();
		void searchMenu_option_clicked();
		void searchMenu_saveB_clicked();
		void createProfile(string s);
		int findHighestAppNum();
		void setAllAppsMenu();
		void allApps_cancel_button_clicked();
		void allApps_search_button_cliked();
		void allApps_next_button_cliked();
		void allApps_prev_button_cliked();
		void allApps_clear();
		void saveToFile();
		void removeStudentFromFile(string num);
		void loadStudentInfo(istringstream &toParse, Student &stu);
		bool loadStudent(string);
	//Public members
	public:
		Controller();
		~Controller();
};
#endif
