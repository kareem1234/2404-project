#include "WorkExperience.h"
using namespace std;
WorkExperience:: WorkExperience(string Title, string Duties,
string Duration, string Start, string End){

	title = Title;
	duties = Duties;
	start = Start;
	end = End;
	setDuration(Duration); 
}

void WorkExperience::save()	{
	saveLog.open("saveLog.txt", ios::app);
	saveLog << "Wor" << "$" << title << "$" << duration << "$" << start << "$" << end << "$" << duties << "$";
	saveLog.close();
}

void WorkExperience::setTitle(string Title){
	title=Title;

}

void WorkExperience::setDuration(string Duration){
	duration = Duration;
}

void WorkExperience:: setDuties(string Duties){
	duties = Duties;
}

void WorkExperience:: setStart(string Start){
	start = Start;
}

void WorkExperience:: setEnd(string End){
	end = End;
}

string WorkExperience::getDuties(){
	return duties;
}


string WorkExperience:: getDuration(){
	return duration;
}

string WorkExperience:: getTitle(){
	return title;
}	

string WorkExperience:: getEnd(){
	return end;
}

string WorkExperience:: getStart(){
	return start;
}

bool WorkExperience::checkDuties(string s)	{
	if(s == "")	return false;
	return true;
}

bool WorkExperience::checkTitle(string s)	{
	if(s.find_first_of("0123456789!@#$%^&*()-_+=|/\\?><,{}[]+~`") != string::npos || s == "")	{
		return false;
	}
	unsigned found = s.find("..");
	if (found != string::npos) return false;
 	return true;
}


