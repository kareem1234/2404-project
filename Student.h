//Student header file

#ifndef STUDENT_H
#define STUDENT_H

#include "Application.h"
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
		string major;
		int year;
		float cgpa;
		float gpa;
		Application* application;
		bool validString(string s);
		bool validInt(string s);
		bool validFloat(string s);

	//Public members
	public:
		Student(Application* app);
		Student(Student& other);
		~Student();
		string getFirstName();
		string getLastName();
		string getStuNum();
		string getEmail();
		string getMajor();
		int getStanding();
		float getCgpa();
		float getGpa();
		Application* getApplications();
		void setName(string name1, string name2);
		void setStuNum(string num);
		void setEmail(string emailAdd);
		void setMajor(string study);
		void setStanding(string standing);
		void setCgpa(string mark);
		void setGpa(string mark);
		void setApplication(Application *app);
		bool checkName(string name);
		bool checkStuNum(string num);
		bool checkEmail(string emailAdd);
		bool checkMajor(string study);
		bool checkStanding(string standing);
		bool checkCgpa(string mark);
		bool checkGpa(string mark);
		void save();
};

#endif
