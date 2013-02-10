//Application source file

#include "Application.h"
#include <iostream>
#include <fstream>
extern ofstream saveLog;

//Static variable initialized
int Application::totalApplications = 0;

//Default constructor
Application::Application(string c = "UNKNOWN"){
	course = c;
	applicationNum = ++totalApplications;
} 

Application:: Application (){
	course = "UNKNOWN";
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
	saveLog << " " << applicationNum + " " + status + " " + course;
}
