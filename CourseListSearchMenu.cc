//CourseListMenu source file

//Include statements
#include "CourseListSearchMenu.h"
using namespace std;

#include <fstream>
#include <cstdlib>

//Default constructor
CourseListSearchMenu::CourseListSearchMenu(int T) 
	: CourseListMenu(T)
{

}

//Finds applications
void CourseListSearchMenu :: findApp(){
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
		if(type.compare("Und")==0){
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
		bool done = false;
		while(!done &&  (symbol.compare("App") != 0) ){
			if(!getline(toParse,symbol,'$')) 
				done = true;

			string appNum, status, course;
			getline(toParse, appNum, '$');
			getline(toParse, status,'$');
			getline(toParse,course,'$');
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
				output1<<"---------------------------"<<endl;
				found = true;
				totalGradApps++;

			}	
		}
	}
	if(found){
		//string undergrad = sortByGpa(totalStuApps,output);
		stringstream returnString;
		returnString<<"		*UNDERGRADS*"<<endl<<sort(totalStuApps,output,10)<<endl;
		returnString<<"		*GRADS*"<<endl<<sort(totalGradApps,output1,9)<<endl;
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
					for(start;start<stop;start++){
						//cout<<"start is"<<start<<endl;
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
		m_ScrolledWindow.set_sensitive(false);
		setString("");

	}else{
		select->set_sensitive(false);
		select->set_label("Select");
		m_ScrolledWindow.set_sensitive(true);
		setString("");


	}


}
Gtk::CheckButton* CourseListSearchMenu:: getOptions(){
	return options;
}

