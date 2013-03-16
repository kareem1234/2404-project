//Application header file

#ifndef APPLICATION_H
#define APPLICATION_H

#include "AssistantCourse.h"
#include "RelatedCourse.h"
#include "WorkExperience.h"
#include "myQ.cc"
#include <fstream>
#include <string>
using namespace std;

//Define Application class
class Application {
	//Private members
	private:
		ofstream saveLog;
		static int totalApplications;
		int applicationNum;
		string status;
		string course;
		myQ<AssistantCourse> assistedCourses;
		myQ<RelatedCourse>   relatedCourses;
		myQ<WorkExperience>  workExperiences;

	//Public members
	public:
		Application(string c = "");
		~Application();
		int getApplicationNum();
		string getStatus();
		string getCourse();
		myQ<AssistantCourse>* getAssisted();
		myQ<RelatedCourse>* getRelated();
		myQ<WorkExperience>* getExperience();
		void setStatus(string stat);
		void setCourse(string c);
		void save();
		Application& operator + ();
		Application& operator - ();
};

#endif
