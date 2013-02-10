#include <iostream>
#include <fstream>
#include <sstream>
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
				string Duration, string Start, String End);
		void save();
		void setTitle();
		void setEnd(string End);
		void setStart(string Start);
		int setDuration(string Duration);
		void setDuties(string Duties);
		string getEnd();
		string getTitle();
		string getStart();
		int    getDuration();
		string getDuties();
		





}
