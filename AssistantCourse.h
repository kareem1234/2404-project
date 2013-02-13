//AssistantCourse header file
#ifndef ASSISTANTCOURSE_H
#define ASSISTANTCOURSE_H

//Include statements
#include "Course.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
extern ofstream saveLog;
using namespace std;

//AssistantCourse class declaration
class AssistantCourse : public Course	{
	//Private data members
	private:
		string supervisor;

	//Public data members
	public:
		AssistantCourse(string = "", string = "", int = 2013, string = "");
		~AssistantCourse();
		string getSupervisor();
		void setSupervisor(string);
		void save();
		static bool checkYear(string);
		static bool checkSupervisor(string);
};

#endif
