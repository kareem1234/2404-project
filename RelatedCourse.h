//RelatedCourse header file
#ifndef RELATEDCOURSE_H
#define RELATEDCOURSE_H

//Include statements
#include "Course.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
extern ofstream saveLog;
using namespace std;

//RelatedCourse class declaration, inherits from Course
class RelatedCourse : public Course 	{
	//Private data members
	private:
		string finalGrade;

	//Public data members
	public:
		RelatedCourse(string = "", string = "", string = "", string = "");
		~RelatedCourse();
		string getFinalGrade();
		void setFinalGrade(string);
		void save();
};

#endif
