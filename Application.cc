//Application source file

#include "Application.h"
#include "AssistantCourse.h"
#include <iostream>

//Static variable initialized
int Application::totalApplications = 0;

//Default constructor
Application::Application(string c)	{
	course = c;
	applicationNum = ++totalApplications;
} 

//Default destructor
Application::~Application()	{
	assistedCourses.clear();
	relatedCourses.clear();
	workExperiences.clear();
}

//Get methods defined
int Application::getApplicationNum(){
	return applicationNum;
}

//Returns status of Application
string Application::getStatus(){
	return status;
}

//Returns the course the application is for
string Application::getCourse(){
	return course;
}
	
//Set methods defined
void Application::setStatus(string stat){
	status = stat;
}

//Sets the course of the application
void Application::setCourse(string c){
	course = c;
}

//Returns the assisted courses if called
myQ<AssistantCourse>* Application::getAssisted()	{
	return &assistedCourses;
}

//Returns the work experience if called
myQ<RelatedCourse>* Application::getRelated()	{
	return &relatedCourses;
}

//Returns the work experience if called
myQ<WorkExperience>* Application::getExperience()	{
	return &workExperiences;
}
	
//Save method saves current application to output file
void Application::save()	{
	saveLog.open("saveLog.txt", ios::app);
	saveLog << "App" << "$" << applicationNum << "$" << status << "$" << course << "$";
	saveLog.close();
	assistedCourses.save();
	relatedCourses.save();
	workExperiences.save();
}

//Updates status to assigned
Application& Application::operator + ()	{
	setStatus("assigned");
	return *this;
}

//Updates status to closed
Application& Application::operator - ()	{
	setStatus("closed");
	return *this;
}
