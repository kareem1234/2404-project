//Student header file

#ifndef STUDENT_H
#define STUDENT_H
// include que class for data storage
#include "myQ.cc"
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
		static bool validString(string s);
		static bool validInt(string s);
		static bool validFloat(string s);

	//Public members
	public:
		Student();
		Student(Student& other);
		~Student();
		myQ<Application> applications;
		string getFirstName();
		string getLastName();
		string getStuNum();
		string getEmail();
		string getMajor();
		int getStanding();
		float getCgpa();
		float getGpa();
		int getNumApps();
		Application* getApplications();
		void setName(string name1, string name2);
		void setStuNum(string num);
		void setEmail(string emailAdd);
		void setMajor(string study);
		void setStanding(string standing);
		void setCgpa(string mark);
		void setGpa(string mark);
		static bool checkName(string name);
		static bool checkStuNum(string num);
		static bool checkEmail(string emailAdd);
		static bool checkMajor(string study);
		static bool checkStanding(string standing);
		static bool checkCgpa(string mark);
		static bool checkGpa(string mark);
		void save();
};

#endif
