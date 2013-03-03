//Student header file

#ifndef STUDENT_H
#define STUDENT_H
// include que class for data storage
#include "myQ.cc"
#include "Application.h"
#include <fstream>
#include <string>
using namespace std;

//Declare Student class
class Student 	{
	//Private members
	private:
		string firstName;
		string lastName;
		string stuNum;
		string email;
		myQ<Application> applications;

	//Protected members
	protected:
		ofstream saveLog;
		static bool validString(string s);
		static bool validInt(string s);
		static bool validFloat(string s);

	//Public members
	public:
		Student();
		~Student();
		string getFirstName();
		string getLastName();
		string getStuNum();
		string getEmail();
		int getNumApps();
		myQ<Application>* getApplications();
		void setName(string name1, string name2);
		void setStuNum(string num);
		void setEmail(string emailAdd);
		static bool checkName(string name);
		static bool checkStuNum(string num);
		static bool checkEmail(string emailAdd);
		void save();
};

#endif
