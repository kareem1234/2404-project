//RelatedCourse source file

//Include statements
#include "RelatedCourse.h"
#include <iostream>

//Default constructor
RelatedCourse::RelatedCourse(string name, string t, string y, string final)
	: Course(name, t, y), finalGrade(final)
{
cout<<"printing info"<<endl;	
cout<<getCourseName()<<endl;
cout<<getTerm()<<endl;
cout<<getYear()<<endl;
cout<<"printing done"<<endl;

}

//Default destructor
RelatedCourse::~RelatedCourse()	{

}

RelatedCourse::RelatedCourse(RelatedCourse& old)	{
	cout<<old.getCourseName()<<endl;
	setCourseName(old.getCourseName());
	setTerm(old.getTerm());
	setYear(old.getYear());
	setFinalGrade(old.getFinalGrade());
}

//Returns final grade of the students course
string RelatedCourse::getFinalGrade()	{
	return finalGrade;
}

//Sets the final grade of the students course
void RelatedCourse::setFinalGrade(string final)	{
	finalGrade = final;
}

//Saves necessary info to file
void RelatedCourse::save()	{
	saveLog<<" "<<"R"<<" "<<getCourseName()<<" "<<getTerm();
	saveLog<<" "<<getYear()<<" "<<getFinalGrade();	

}
