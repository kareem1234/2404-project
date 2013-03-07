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
		string 	courseName;
		string 	term;
		string 	year;

	//Protected data mambers
	protected:
		ofstream saveLog;
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
