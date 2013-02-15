//Application source file

#include "Application.h"
#include "AssistantCourse.h"
#include <iostream>
#include <fstream>
extern ofstream saveLog;

//Static variable initialized
int Application::totalApplications = 0;

//Default constructor
Application::Application(string c = ""){
	course = c;
	applicationNum = ++totalApplications;
} 

Application:: Application (){
	course = "";
	applicationNum = ++totalApplications;

}

//Get methods defined
int Application::getApplicationNum(){
	return applicationNum;
}

string Application::getStatus(){
	return status;
}

string Application::getCourse(){
	return course;
}
	
//Set methods defined
void Application::setStatus(string stat){
	status = stat;
	
}

void Application::setCourse(string c){
	course = c;

}
	
//Save method saves current application to output file
void Application::save()	{
	saveLog << "App" << "$" << applicationNum << "$" << status << "$" << course << "$";
	int l = assistedCourses.length();
	for(int i = 0; i< l; i++){
		AssistantCourse* a = new AssistantCourse;

		assistedCourses.popFront(a);

		a->save();

		assistedCourses.pushBack(a);

	}
	l = relatedCourses.length();
	for(int i= 0; i<l; i++)	{
		RelatedCourse *r = new RelatedCourse;

		cout<<r<<endl;
		relatedCourses.popFront(r);

		r->save();

		relatedCourses.pushBack(r);

	}
	l= workExperiences.length();
	for(int i= 0; i<l; i++)	{
		WorkExperience *work = new WorkExperience;

		workExperiences.popFront(work);

		work->save();

		workExperiences.pushBack(work);

	}
}





