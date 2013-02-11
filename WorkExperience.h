#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;
extern ofstream saveLog;

class WorkExperience{
	
	private:
		string title;
		string duties;
		int duration;
		string start;
		string end;
		


	public:
		WorkExperience(string Title, string Duties,
				string Duration, string Start, string End);
		void save();
		void setTitle(string Title);
		void setEnd(string End);
		void setStart(string Start);
		int setDuration(string Duration);
		void setDuties(string Duties);
		string getEnd();
		string getTitle();
		string getStart();
		int    getDuration();
		string getDuties();
		





};
