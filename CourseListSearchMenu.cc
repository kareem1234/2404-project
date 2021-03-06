//CourseListMenu source file

//Include statements
#include "CourseListSearchMenu.h"
using namespace std;

#include <fstream>
#include <cstdlib>
#include <stdio.h>

//Default constructor
CourseListSearchMenu::CourseListSearchMenu(int T) 
	: CourseListMenu(T)
{

}

//Finds applications

void CourseListSearchMenu::findApp(){
	saveB->set_sensitive(true);
	string line;
	stringstream output;
	stringstream output1;
	//stringstream newOutput;
	bool found = false;
	int totalStuApps = 0;
	int totalGradApps = 0;

	ifstream myfile("saveLog.txt");
	while(getline(myfile,line)){
		istringstream toParse (line, istringstream::in);
		string  type, firstName, lastName, stuNum , email;
	        string  major, standing, cgpa ,gpa;
		string research, program, supervisor; 
		getline(toParse,type,'$');
		if(type.compare("Und") == 0){
			getline(toParse,firstName,'$');
			getline(toParse,lastName,'$');
			getline(toParse,stuNum,'$');
			getline(toParse,email,'$');
			getline(toParse,major,'$');
			getline(toParse,cgpa,'$');
			getline(toParse,gpa,'$');
			getline(toParse,standing,'$');
		}else{
			getline(toParse,firstName,'$');
			getline(toParse,lastName,'$');
			getline(toParse,stuNum,'$');
			getline(toParse,email,'$');
			getline(toParse,research,'$');
			getline(toParse,program,'$');
			getline(toParse,supervisor,'$');
		}
		
		string symbol = "";
		while(getline(toParse,symbol,'$'))	{
			
			if(symbol.compare("App") == 0)	{
				string appNum, status, course;
				getline(toParse, appNum, '$');
				getline(toParse, status,'$');
				getline(toParse,course,'$');
				
				if(settings(status)){
					if( (course.compare(getString()) == 0 || options->get_active()) && type.compare("Und") ==0 ){
						output<<"Applicant type: "<<"Undergraduate"<<endl;
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
					}else if( (course.compare(getString())==0 || options->get_active()) && type.compare("Gra") == 0 ){
						output1<<"Applicant type: "<<"Graduate"<<endl;
						output1<<"Name: "<<firstName<<" "<<lastName<<endl;
						output1<<"Student Number: "<<stuNum<<endl;
						output1<<"Email: "<<email<<endl;
						output1<<"Research Area: "<<research<<endl;
						output1<<"Program: "<<program<<endl;
						output1<<"Supervisor: "<<supervisor<<endl;
						output1<<"Applied to TA: "<<course<<endl;
						output1<<"----------------------------"<<endl;
						found = true;
						totalGradApps++;
					}
				}
			}
		}
	}
	if(found){
		stringstream returnString;
		string fix(sort(totalStuApps,output,10));
		if(type == 2)stringFix(fix);
		returnString<<"             *UNDERGRADS*           "<<endl<<fix<<endl;
		fix= sort(totalGradApps,output1,9);
		if(type == 2)stringFix(fix);
		returnString<<"             *GRADS*                "<<endl<<fix<<endl;
		setString(returnString.str());
	}	
	else		setString("NO APPLICATION FOUND");
}

string CourseListSearchMenu::sort(int totalApps, stringstream& output, int sortType){
			stringstream newOutput;
			int length = sortType*totalApps;
			string toSort[length];
			int    pos  =0;
			int    pos1 =0;
			int    pos2 =0;
			int    intSort[totalApps];
			string stringSort[totalApps];
			int    intSort1[totalApps];
			//int count = 0;
			for(int i=0;i<length;i++){
				getline(output,toSort[i],'\n');	
				// extract gpa's
				if(toSort[i].at(0) =='G'){
					istringstream buffer(toSort[i]);
					buffer.ignore(256,' ');
					buffer>>intSort[pos++];
				}
				//extract research strings
				if(toSort[i].at(0)== 'R'){
					stringstream buffer(toSort[i].substr(15,30));
					buffer>>stringSort[pos2++];
				}
				// extract course numbers
				if(toSort[i].at(0)=='A')
					if(toSort[i].at(6)=='d'){
						string courseNumber = toSort[i].substr(toSort[i].length()-5,5);
						stringstream buffer(courseNumber);
						buffer>>intSort1[pos1++];
				}
			}
			// loop through intSort
			bool done = false;
			while(done == false){
				done = true;
				int highest= -1;
				string higher="zzzzzzzzzzz";
				int index = -1;
				if(sortType == 10){
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
				}else{
						if(! (options->get_active()))
						for(int i = 0; i<pos2; i++){
							if(stringSort[i] != "" && stringSort[i].compare(higher)<0 ){
								higher = stringSort[i];
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
								if(stringSort[i] != "" && stringSort[i].compare(stringSort[index])<=0 ){
									higher= stringSort[i];
									index = i;
									done = false;								
								}
							}
						}

					}

				}
				if(!done){
					if(options->get_active() ) intSort1[index] = -1;
					else if(sortType == 10) intSort[index]=-1; 
					else stringSort[index] = "";
					//find the associated gpa and send it to the new output buffer				
					int start = index*sortType;
					int stop = start+sortType;
					for(start;start<stop;start++){;
						newOutput<<toSort[start]<<endl;						

					}					
				}				
			}
			return newOutput.str();
}
void CourseListSearchMenu::stringFix(string &output){
	size_t start = 0;
	while( (start = output.find("\n",start)) != string::npos ){
		output.replace(start,1,"-");		
		start+=3;
	}

	start = 0;
	string l ="---------------------------";
	while( (start = output.find(l,start)) != string::npos ){
		output.replace(start,l.length(),"\n");		
		start++;
	}




}

void CourseListSearchMenu::checked(){
	if(options->get_active()){
		select->set_sensitive(true);
		select->set_label("VIEW ALL APPLICATIONS");
		m_ScrolledWindow.set_sensitive(false);
		setString("");
		saveB->set_sensitive(false);

	}else{
		select->set_sensitive(false);
		select->set_label("Select");
		m_ScrolledWindow.set_sensitive(true);
		setString("");
		saveB->set_sensitive(false);


	}


}
bool CourseListSearchMenu:: settings(string status){
	if(type == 1){
		if(status.compare("pending")==0)	
		return true;
	}
	else if(type == 2){
		if(status.compare("assigned")==0)
			return true;

		return false;
	
	}
	return false;
}

void CourseListSearchMenu::print(){
	ofstream toSave;
	string s = m_refTextBuffer->get_text();
	if(!options->get_active()){
		if(type ==1){
			string fileName = getString();
			fileName+= " pending applications";
			std::remove(fileName.c_str());
			toSave.open(fileName.c_str());
		}else if(type ==2){
			string fileName = getString();
			fileName+=" Succesfull applications";
			std::remove(fileName.c_str());
			toSave.open(fileName.c_str());		
		}
	}else{
		if(type ==1){
			std::remove("All Pending Applications.txt");
			toSave.open("All Pending Applications.txt");
		}else if(type ==2){
			std::remove("All Succesfull Applications.txt");
			toSave.open("All Succesfull Applications.txt");
		}
	}
	toSave<<s.c_str();
	toSave.close();
	saveB->set_sensitive(false);

}
Gtk::Button* CourseListSearchMenu:: getSave(){
	return saveB;
}
Gtk::CheckButton* CourseListSearchMenu:: getOptions(){
	return options;
}

