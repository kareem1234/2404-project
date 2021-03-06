//Grad header file

#ifndef GRAD_H
#define GRAD_H

#include "Student.h"

class Grad : public Student		{
	//Private members
	private:
		string research;
		string program;
		string supervisor;

	//Public members
	public:
		Grad(string f = "", string l = "", string s = "", string e = "", string r = "", string p = "", string sup = "");
		~Grad();
		string getResearch();
		string getProgram();
		string getSupervisor();
		void setResearch(string res);
		void setProgram(string pro);
		void setSupervisor(string sup);
		static bool checkSupervisor(string sup);
		void save();
};

#endif
