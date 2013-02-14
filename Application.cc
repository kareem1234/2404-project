//Application source file

#include "Application.h"
#include "AssistantCourse.h"
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
	cout<<"here?"<<endl;
	int l = assistedCourses.length();
	cout<<"not here"<<endl;
	for(int i = 0; i< l; i++)	{
		AssistantCourse Course;
		cout<<"this is the spot1"<<endl;
		assistedCourses.popFront(&Course);
		cout<<"popped assitant course "<< i << endl;
		Course.save();
		cout<<"saved assitant course "<< i << endl;
		assistedCourses.pushBack(&Course);
		cout<<"pushed assitant course "<< i << endl;
	}
	l = relatedCourses.length();
	for(int i= 0; i<l; i++)	{
		RelatedCourse *r = new RelatedCourse;
		cout<<"this is the spot2"<<endl;
		cout<<r<<endl;
		relatedCourses.popFront(r);
		cout<<"popped related course "<< i << endl;
		r->save();
		cout<<"saved related course "<< i << endl;
		relatedCourses.pushBack(r);
		cout<<"pushed related course "<< i << endl;
		cout<<relatedCourses.length()<<endl;
	}
	l= workExperiences.length();
	for(int i= 0; i<l; i++)	{
		WorkExperience work;
		cout<<"this is the spot3"<<endl;
		workExperiences.popFront(&work);
		cout<<"popped experience  "<< i << endl;
		work.save();
		cout<<"saved experience  "<< i << endl;
		workExperiences.pushBack(&work);
		cout<<"pushed experience  "<< i << endl;
	}
}





