//Application header file

#ifndef APPLICATION_H
#define APPLICATION_H

#include "AssistantCourse.h"
#include "RelatedCourse.h"
#include "WorkExperience.h"
#include "myQ.cc"
#include <string>
using namespace std;

//Define Application class
class Application {
	//Private members
	private:
		static int totalApplications;
		int applicationNum;
		string status;
		string course;
	//Public members
	public:
		Application(string c);
		Application();
		myQ<AssistantCourse> assistedCourses;
		myQ<RelatedCourse>   relatedCourses;
		myQ<WorkExperience>  workExperiences;
		int getApplicationNum();
		string getStatus();
		string getCourse();
		void setStatus(string stat);
		void setCourse(string c);
		void save();
};

#endif
