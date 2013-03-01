//Course header file
#ifndef COURSE_H
#define COURSE_H

//Include statements
#include <fstream>
#include <string>
using namespace std;

//Course class declaration
class Course	{
	//Private data members
	private:
		ofstream saveLog;
		string 	courseName;
		string 	term;
		string 	year;

	//Public data members
	public:	
		Course(string = "", string = "", string = "");
		string getCourseName();
		string getTerm();
		string getYear();
		void setCourseName(string);
		void setTerm(string);
		void setYear(string);
		void save();
		static int checkYear(string s);
};

#endif
