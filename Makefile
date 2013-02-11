Assignment1:	Main.o Controller.o Student.o Application.o GenInfoMenu.o StudentMenu.o LoginMenu.o CourseListMenu.o TeacherMenu.o AssistantCourse.o RelatedCourse.o WorkExperience.o Course.o
		g++ -o Assignment1 Main.o Controller.o Student.o Application.o GenInfoMenu.o StudentMenu.o LoginMenu.o CourseListMenu.o TeacherMenu.o AssistantCourse.o RelatedCourse.o Course.o  WorkExperience.o `pkg-config gtkmm-3.0 --cflags --libs`

Main.o:		Main.h Main.cc 
		g++ -c Main.cc `pkg-config gtkmm-3.0 --cflags --libs`

Controller.o:	Controller.h Controller.cc
		g++ -c Controller.cc `pkg-config gtkmm-3.0 --cflags --libs`

Student.o:	Student.h Application.h Student.cc
		g++ -c Student.cc

Application.o:	Application.h Application.cc
		g++ -c Application.cc

GenInfoMenu.o:	GenInfoMenu.h GenInfoMenu.cc
		g++ -c GenInfoMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

StudentMenu.o:	StudentMenu.h StudentMenu.cc
		g++ -c StudentMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

LoginMenu.o:	LoginMenu.h LoginMenu.cc
		g++ -c LoginMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

CourseListMenu.o:	CourseListMenu.h CourseListMenu.cc
			g++ -c CourseListMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

TeacherMenu.o:	TeacherMenu.h TeacherMenu.cc
		g++ -c TeacherMenu.cc `pkg-config gtkmm-3.0 --cflags --libs`

WorkExperience.o:	WorkExperience.h WorkExperience.cc
			g++ -c WorkExperience.cc

RelatedCourse.o:	RelatedCourse.h RelatedCourse.cc
			g++ -c RelatedCourse.cc

AssistantCourse.o:	AssistantCourse.h AssistantCourse.cc
			g++ -c AssistantCourse.cc	
Course.o:		Course.h Course.cc
			g++ -c Course.cc

clean: 		
		rm *.o *.h~ *.cc~ saveLog.txt Assignment1
