//CourseListMenu source file

//Include statements
#include "CourseListSearchMenu.h"
using namespace std;

#include <fstream>
#include <cstdlib>

//Default constructor
CourseListSearchMenu::CourseListSearchMenu(int Type) 
	: CourseListMenu(type)
{
	
}

//Finds applications
void CourseListSearchMenu :: findApp(){
	string line;
	stringstream output;
	stringstream output1;
	stringstream newOutput;
	bool found = false;
	int totalStuApps = 0;
	int totalGradApps = 0;

	ifstream myfile("saveLog.txt");
	while(getline(myfile,line)){
		istringstream toParse (line, istringstream::in);
		string firstName, lastName, stuNum , email, major, standing, cgpa ,gpa;
		getline(toParse,firstName,'$');
		getline(toParse,lastName,'$');
		getline(toParse,stuNum,'$');
		getline(toParse,email,'$');
		getline(toParse,major,'$');
		getline(toParse,cgpa,'$');
		getline(toParse,gpa,'$');
		getline(toParse,standing,'$');

		string symbol = "";
		bool done = false;
		while(!done &&  (symbol.compare("Ap") != 0) ){
			if(!getline(toParse,symbol,'$')) 
				done = true;
			string appNum, status, course;
			getline(toParse, appNum, '$');
			getline(toParse, status,'$');
			getline(toParse,course,'$');
			if(course.compare(getString()) == 0 || options->get_active()){
				output<<"Name: "<<firstName<<" "<<lastName<<endl;
				output<<"Student Number: "<<stuNum<<endl;
				output<<"Email: "<<email<<endl;
				output<<"Major: "<<major<<endl;
				output<<"Year Standing: "<<standing<<endl;
				output<<"Cgpa: "<<cgpa<<endl;
				output<<"Gpa: "<<gpa<<endl;
				output<<"Applied to TA: "<<course<<endl;
				output<<"---------------------------"<<endl;
				found = true;
				totalStuApps++;
			}	
		}
	}
	if(found){
		if( (totalStuApps + totalGradApps) == 1 ){
			setString(output.str());
			return;
		}else{
			//string undergrad = sortByGpa(totalStuApps,output);
			stringstream returnString;
			returnString<<"UNDERGRADS----------------"<<endl<<sortByGpa(totalStuApps,output,newOutput)<<endl;
			setString(returnString.str());
		}
	}	
	else		setString("NO APPLICATION FOUND");
}

string CourseListSearchMenu::sortByGpa(int totalApps, stringstream& output,stringstream& newOutput){
			int length = 9*totalApps;
			string toSort[length];
			int    pos = 0;
			int    pos1= 0;
			int    intSort[totalApps];
			int    intSort1[totalApps];
			//int count = 0;
			for(int i=0;i<length;i++){
				getline(output,toSort[i],'\n');	
				// extract gpa's
				if(toSort[i].at(0) =='G'){
					istringstream buffer(toSort[i]);
					buffer.ignore(256,' ');
					buffer>>intSort[pos];
					pos++;
				}
				// extract course numbers
				if(toSort[i].at(0)=='C' && toSort[i].at(1)=='O'){
					string courseNumber = toSort[i].substr(5,5);
					stringstream buffer(courseNumber);
					buffer>>intSort1[pos1];
					pos1++;	
				}
			}
			// loop through intSort
			bool done = false;
			while(done == false){
				done = true;
				int highest= -1;
				int index = -1;
				if(! (options->get_active()))
					for(int i = 0; i<pos; i++){
						if(intSort[i] != -1 && intSort[i] >=highest){
							highest = intSort[i];
							index = i;
							done = false;
						}
					}
				else{
					for(int i=0; i<pos1;i++){
						if(intSort1[i] != -1 && intSort1[i] > highest ){
							highest = intSort1[i];
							index = i;							
							done=false;
						}else if(intSort1[i] != -1 && intSort1[i] == highest){
							if(intSort[i] >= intSort[index]){
								highest = intSort1[i];
								index = i;
								done = false;								
							}
						}
					}

				}
				if(!done){
					if(options->get_active()) intSort[index] = -1;
					else intSort1[index]=-1; 
					//find the associated gpa and send it to the new output buffer				
					int start = index*9;
					int stop = start+9;
					for(start;start<stop;start++){
						newOutput<<toSort[start]<<endl;						

					}					
				}				
			}
			return newOutput.str();
}

void CourseListSearchMenu::checked(){
	if(options->get_active()){
		select->set_sensitive(true);
		select->set_label("View All Aplications");
		m_ScrolledWindow2.set_sensitive(false);

	}else{
		select->set_sensitive(false);
		select->set_label("Select");
		m_ScrolledWindow2.set_sensitive(true);
		
	
	}


}

