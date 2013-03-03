//Undergrad header file

#ifndef UNDERGRAD_H
#define UNDERGRAD_H

#include "Student.h"

class Undergrad : public Student	{
	//Private members
	private:
		string major;
		int year;
		float cgpa;
		float gpa;

	//Public members
	public:
		Undergrad();
		~Undergrad();
		string getMajor();
		int getStanding();
		float getCgpa();
		float getGpa();
		void setMajor(string study);
		void setStanding(string standing);
		void setCgpa(string mark);
		void setGpa(string mark);
		static bool checkMajor(string study);
		static bool checkStanding(string standing);
		static bool checkCgpa(string mark);
		static bool checkGpa(string mark);
		void save();
};

#endif
