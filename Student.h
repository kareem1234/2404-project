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
		virtual string getFirstName() = 0;
		virtual string getLastName() = 0;
		virtual string getStuNum() = 0;
		virtual string getEmail() = 0;
		virtual int getNumApps() = 0;
		virtual myQ<Application>* getApplications() = 0;
		virtual void setName(string name1, string name2) = 0;
		virtual void setStuNum(string num) = 0;
		virtual void setEmail(string emailAdd) = 0;
		virtual bool duplicateApp(string) = 0;
		virtual Application* getApp(string) = 0;
		virtual void save() = 0;
		static bool checkName(string name);
		static bool checkStuNum(string num);
		static bool checkEmail(string emailAdd);
		virtual string getMajor() {};
		virtual string getStanding() {};
		virtual string getCgpa() {};
		virtual string getGpa() {};
		virtual void setMajor(string study) {};
		virtual void setStanding(string standing) {};
		virtual void setCgpa(string mark) {};
		virtual void setGpa(string mark) {};
		virtual string getResearch() {};
		virtual string getProgram() {};
		virtual string getSupervisor() {};
		virtual void setResearch(string res) {};
		virtual void setProgram(string pro) {};
		virtual void setSupervisor(string sup) {};
};

#endif
