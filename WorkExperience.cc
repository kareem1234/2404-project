#include "WorkExperience.h"

WorkExperience:: WorkExperience(string Title, string Duties,
string Duration, string Start, String End){

title = Title;
duties = Duties;
start = Start;
end = End;

setDuration(Duration); 
}

void WorkExperience::save(){
	saveLog<<" "<<title<<" "<< duration<< " "<<start<<" "<<end<<" "<< duties;

}

void WorkExperience::setTitle(string Title){
	title=Title;

}

int WorkExperience::setDuration(String Duration){
	stringstream toConver(Duration);
	if( ! (toConvert >> duration) )
		return duration = -1;

	return 0;
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


int WorkExperience:: getDuration(){

	return duration;
}

string WorkExperience:: getTitle(){
	return title;
}	

string WorkExperience:: getEnd(){
	
	return end;
}

string WorkExpereince:: getStart(){

	return start;
}






