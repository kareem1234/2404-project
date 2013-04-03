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
		virtual string getFirstName();
		virtual string getLastName();
		virtual string getStuNum();
		virtual string getEmail();
		virtual int getNumApps();
		virtual myQ<Application>* getApplications();
		virtual void setName(string name1, string name2);
		virtual void setStuNum(string num);
		virtual void setEmail(string emailAdd);
		virtual bool duplicateApp(string);
		virtual Application* getApp(string);
		virtual void save() = 0;
		static bool checkName(string name);
		static bool checkStuNum(string num);
		static bool checkEmail(string emailAdd);
		virtual string getMajor() { return ""; };
		virtual string getStanding() { return ""; };
		virtual string getCgpa() { return ""; };
		virtual string getGpa() { return ""; };
		virtual void setMajor(string study) {};
		virtual void setStanding(string standing) {};
		virtual void setCgpa(string mark) {};
		virtual void setGpa(string mark) {};
		virtual string getResearch() { return ""; };
		virtual string getProgram() { return ""; };
		virtual string getSupervisor() { return ""; };
		virtual void setResearch(string res) {};
		virtual void setProgram(string pro) {};
		virtual void setSupervisor(string sup) {};
};

#endif
