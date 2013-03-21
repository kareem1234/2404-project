//Application source file

#include "Application.h"
#include "AssistantCourse.h"
#include <iostream>

//Static variable initialized
int Application::totalApplications = 0;

//Default constructor
Application::Application(string c,int total, string stat, int num)	{
	if(total != -1 )totalApplications = total;
	course = c;
	status = stat;
	if(num == 0)	applicationNum = ++totalApplications;
	else	applicationNum = num;
} 

//Default destructor
Application::~Application()	{
	assistedCourses.clear();
	relatedCourses.clear();
	workExperiences.clear();
}
void Application::setTotalApplications(int i){
	totalApplications = i;

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

//Returns whether there is an identical assistant course
bool Application::duplicateAss(string course)	{
	int i;

	for(i = 0; i < assistedCourses.length(); i++)	{
		if(assistedCourses[i]->getCourseName() == course)
			return true;
	}
	return false;
}

//Returns whether there is an identical related course
bool Application::duplicateRel(string course)	{
	int i;

	for(i = 0; i < relatedCourses.length(); i++)	{
		if(relatedCourses[i]->getCourseName() == course)	{
			cout << "HI" << endl;		
			return true;
		}
	}
	return false;

}

//Returns whether there is an identical work experience
bool Application::duplicateWor(string title)	{
	int i;

	for(i = 0; i < workExperiences.length(); i++)	{
		if(workExperiences[i]->getTitle() == title)
			return true;
	}
	return false;
}

//Returns assisted course with given course
AssistantCourse* Application::findAss(string course)	{
	int i;

	for(i = 0; i < assistedCourses.length(); i++)	{
		if(assistedCourses[i]->getCourseName() == course)
			return assistedCourses[i];
	}
	return 0;
}

//Returns assisted course with given course
RelatedCourse* Application::findRel(string course)	{
	int i;

	for(i = 0; i < relatedCourses.length(); i++)	{
		if(relatedCourses[i]->getCourseName() == course)
			return relatedCourses[i];
	}
	return 0;
}
	
//Returns work experience with given title	
WorkExperience* Application::findWor(string title)	{
	int i;

	for(i = 0; i < workExperiences.length(); i++)	{
		if(workExperiences[i]->getTitle() == title)
			return workExperiences[i];
	}
	return 0;
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
