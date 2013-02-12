//RelatedCourse source file

//Include statements
#include "RelatedCourse.h"

//Default constructor
RelatedCourse::RelatedCourse(string name, string t, int y, string final)
	: Course(name, t, y), finalGrade(final)
{	}

//Default destructor
RelatedCourse::~RelatedCourse()	{

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
