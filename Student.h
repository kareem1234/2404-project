//Student header file

#ifndef STUDENT_H
#define STUDENT_H

//Include statements
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
		Student(string f = "", string l = "", string s = "", string e = "");
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
		bool duplicateApp(string);
		Application* getApp(string);
		static bool checkName(string name);
		static bool checkStuNum(string num);
		static bool checkEmail(string emailAdd);
		void save();
};

#endif
