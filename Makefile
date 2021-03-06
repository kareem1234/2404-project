all : 	Qtest Assignment4

Qtest:	Qtest.o myQ.o
	g++ -o Qtest Qtest.o myQ.o

Qtest.o:	Qtest.cc
		g++ -c Qtest.cc

Assignment4:	Main.o Controller.o Student.o Undergrad.o Grad.o Application.o GenInfoMenu.o StudentMenu.o LoginMenu.o CourseListMenu.o TeacherMenu.o RelatedCourseMenu.o AllAppsMenu.o WorkExperience.o TACourseMenu.o AssistantCourse.o RelatedCourse.o Course.o WorkExperienceMenu.o StudentTypeMenu.o myQ.o CourseListSearchMenu.o AppListMenu.o VerificationMenu.o
		g++ -o Assignment4 Main.o Controller.o Student.o Undergrad.o Grad.o Application.o TeacherMenu.o GenInfoMenu.o StudentMenu.o AllAppsMenu.o LoginMenu.o CourseListMenu.o AppListMenu.o VerificationMenu.o CourseListSearchMenu.o RelatedCourseMenu.o WorkExperience.o TACourseMenu.o AssistantCourse.o RelatedCourse.o Course.o myQ.o WorkExperienceMenu.o StudentTypeMenu.o `pkg-config gtkmm-3.0 --cflags --libs`

Main.o:		Main.h Main.cc 
		g++ -c Main.cc `pkg-config gtkmm-3.0 --cflags --libs`

Controller.o:	Controller.h Controller.cc
		g++ -c Controller.cc `pkg-config gtkmm-3.0 --cflags --libs`

Student.o:	Student.h Application.h Student.cc
		g++ -c Student.cc

Undergrad.o:	Undergrad.h Student.h Undergrad.cc
		g++ -c Undergrad.cc

Grad.o:	Grad.h Student.h Grad.cc
	g++ -c Grad.cc

Application.o:	Application.h Application.cc
		g++ -c Application.cc

GenInfoMenu.o:	GenInfoMenu.h GenInfoMenu.cc
		g++ -c GenInfoMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

AllAppsMenu.o:	AllAppsMenu.h AllAppsMenu.cc
		g++ -c AllAppsMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

StudentMenu.o:	StudentMenu.h StudentMenu.cc
		g++ -c StudentMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

LoginMenu.o:	LoginMenu.h LoginMenu.cc
		g++ -c LoginMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

VerificationMenu.o:	VerificationMenu.h VerificationMenu.cc
			g++ -c VerificationMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

StudentTypeMenu.o:	StudentTypeMenu.h StudentTypeMenu.cc
			g++ -c StudentTypeMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

CourseListMenu.o:	CourseListMenu.h CourseListMenu.cc
			g++ -c CourseListMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`
AppListMenu.o:	AppListMenu.h AppListMenu.cc
		g++ -c AppListMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

CourseListSearchMenu.o: CourseListSearchMenu.h CourseListSearchMenu.cc
			g++ -c CourseListSearchMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

WorkExperienceMenu.o:	WorkExperienceMenu.h WorkExperienceMenu.cc
			g++ -c WorkExperienceMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

TeacherMenu.o:	TeacherMenu.h TeacherMenu.cc
		g++ -c TeacherMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

RelatedCourseMenu.o:	RelatedCourseMenu.h RelatedCourseMenu.cc
			g++ -c RelatedCourseMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

WorkExperience.o:	WorkExperience.h WorkExperience.cc
			g++ -c WorkExperience.cc `pkg-config gtkmm-3.0 --cflags --libs`

TACourseMenu.o:	TACourseMenu.h TACourseMenu.cc
		g++ -c TACourseMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

RelatedCourse.o:	RelatedCourse.h RelatedCourse.cc
			g++ -c RelatedCourse.cc

AssistantCourse.o:	AssistantCourse.h AssistantCourse.cc
			g++ -c AssistantCourse.cc	

Course.o:	Course.h Course.cc
		g++ -c Course.cc

myQ.o:	myQ.cc 
	g++ -c myQ.cc

clean1:	
	rm Qtest.o myQ.o Qtest

clean: 		
		rm *.o *.h~ *.cc~ *.txt~ *Applications.txt COMP* temp.txt saveLog.txt Makefile~ Assignment4
