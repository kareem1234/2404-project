//WorkExperience header file

#ifndef WORKEXPERIENCE_H
#define WORKEXPERIENCE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class WorkExperience	{
	
	private:
		ofstream saveLog;
		string title;
		string duties;
		string duration;
		string start;
		string end;
		


	public:
		WorkExperience(string Title = "", string Duties = "",
				string Duration = "", string Start = "", string End = "");
		void save();
		void setTitle(string Title);
		void setEnd(string End);
		void setStart(string Start);
		void setDuration(string Duration);
		void setDuties(string Duties);
		string getEnd();
		string getTitle();
		string getStart();
		string getDuration();
		string getDuties();
		static bool checkDuties(string);
		static bool checkTitle(string);	
};

#endif
