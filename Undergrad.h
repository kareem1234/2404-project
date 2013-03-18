//Undergrad header file

#ifndef UNDERGRAD_H
#define UNDERGRAD_H

#include "Student.h"

class Undergrad : public Student	{
	//Private members
	private:
		string maj;
		string year;
		string cgpa;
		string gpa;

	//Public members
	public:
		Undergrad(string f = "", string l = "", string s = "", string e = "", string m = "", string y = "", string c = "", string g = "");
		~Undergrad();
		string getMajor();
		string getStanding();
		string getCgpa();
		string getGpa();
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
