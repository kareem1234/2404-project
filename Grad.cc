//Grad source file
//dhsfjkhsdkjfhsjkd//
//Include statements
#include "Grad.h"

//Default constructor
Grad::Grad(string f, string l, string s, string e, string r, string p, string sup)
	: Student(f,l,s,e), research(r), program(p), supervisor(sup)
{	}

//Default destructor
Grad::~Grad()	{

}

//Returns the research area when called
string Grad::getResearch()	{
	return research;
}

//Returns the program when called
string Grad::getProgram()	{
	return program;
}

//Returns supervisor when called
string Grad::getSupervisor()	{
	return supervisor;
}

//Sets research area with given string
void Grad::setResearch(string res)	{
	research = res;
}

//Sets program with given string
void Grad::setProgram(string pro)	{
	program = pro;
}

//Sets supervisor with given string
void Grad::setSupervisor(string sup)	{
	supervisor = sup;
}

//Checks given string to see if proper supervisor
bool Grad::checkSupervisor(string sup)	{
	if(sup.find_first_of("0123456789!@#$%^&*()-_+=|/\\?><,{}[]+~`") != string::npos || sup == "")	{
		return false;
	}
	unsigned found = sup.find("..");
	if (found != string::npos) return false;
 	return true;
}

//Saves the grad to file
void Grad::save()	{
	saveLog.open("saveLog.txt", ios::app);
	saveLog << "Gra" << "$" << getFirstName() << "$" << getLastName() << "$" << getStuNum() << "$" << getEmail() << "$" << research << "$" << program << "$" << supervisor << "$";
	saveLog.close();
	getApplications()->save();

	saveLog.open("saveLog.txt", ios::app);
	saveLog << endl;
	saveLog.close();
}
