//Course header file
#ifndef COURSE_H
#define COURSE_H

//Include statements
#include <string>
using namespace std;

//Course class declaration
class Course	{
	//Private data members
	private:
		string 	courseName;
		string 	term;
		int 	year;

	//Public data members
	public:	
		Course(string, string = "WINTER", int = 2013);
		~Course();
		string getCourseName();
		string getTerm();
		int getYear();
		void setCourseName(string);
		void setTerm(string);
		void setYear(int);
		void save();
		static int checkYear(string s);
};

#endif
