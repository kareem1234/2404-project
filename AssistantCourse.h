//AssistantCourse header file
#ifndef ASSISTANTCOURSE_H
#define ASSISTANTCOURSE_H

//Include statements
#include "Course.h"
#include <string>
using namespace std;

//AssistantCourse class declaration
class AssistantCourse : public Course	{
	//Private data members
	private:
		string supervisor;

	//Public data members
	public:
		AssistantCourse(string, string, int, string);
		~AssistantCourse();
		string getSupervisor();
		void setSupervisor(string);
		void save();
};

#endif
