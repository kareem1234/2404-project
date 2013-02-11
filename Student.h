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
		bool validString(string s);
		bool validInt(string s);
		bool validFloat(string s);

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
