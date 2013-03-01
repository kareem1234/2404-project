//AssistantCourse header file
#ifndef ASSISTANTCOURSE_H
#define ASSISTANTCOURSE_H

//Include statements
#include "Course.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//AssistantCourse class declaration
class AssistantCourse : public Course	{
	//Private data members
	private:
		ofstream saveLog;
		string supervisor;

	//Public data members
	public:
		AssistantCourse(string = "", string = "", string = "", string = "");
		string getSupervisor();
		void setSupervisor(string);
		void save();
		static bool checkYear(string);
		static bool checkSupervisor(string);
};

#endif
