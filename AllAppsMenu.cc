#include "AllAppsMenu.h"


AllAppsMenu:: AllAppsMenu(){
	// init labels
	searchOptions = new Gtk::Label("Search Options");
	searchOptions->set_size_request(150, 30);

	searchWord = new Gtk::Label(" Enter Search Word:");
	searchWord->set_size_request(150,30);

	// init checkButtons
	appNumber = new Gtk::RadioButton("By app Number");
	appNumber->set_size_request(150,30);
	
	stuNumber = new Gtk::RadioButton("By student Number");
	stuNumber->set_size_request(150,30);
	
	name = new Gtk::RadioButton("By name");
	name->set_size_request(150,30);

	 Gtk::RadioButton::Group group = appNumber->get_group();
    	 name->set_group(group);
   	 stuNumber->set_group(group);

	// init buttons
	previous = new Gtk::Button("PREVIOUS");
	previous->set_size_request(150,30);
	previous->set_sensitive(false);
	
	cancel = new Gtk::Button("CANCEL");
	cancel->set_size_request(150,30);

	next = new Gtk::Button("NEXT");
	next->set_size_request(150,30);
	next->set_sensitive(false);
	
	search = new Gtk::Button("SEARCH");
	search->set_size_request(150,30);
		

	//////////////////////////////
	searchTerm = new Gtk::Entry();
	grid = new Gtk::Grid();
	m_TextView = new Gtk::TextView;
	m_TextView->set_editable(false);
	m_ScrolledWindow.add(*m_TextView);
	m_ScrolledWindow.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
	m_refTextBuffer = Gtk::TextBuffer::create();
	m_TextView->set_buffer(m_refTextBuffer);
	m_ScrolledWindow.set_size_request(250,300);

	// grid init
	grid->attach(*searchOptions,0,0,1,1);
	grid->attach(*appNumber,0,1,1,1);
	grid->attach(*stuNumber,1,1,1,1);
	grid->attach(*name,0,2,1,1);
	grid->attach(*searchWord,0,3,1,1);
	grid->attach(*searchTerm,1,3,1,1);
	grid->attach(m_ScrolledWindow,0,4,2,4);
	grid->attach(*search,0,8,2,1);
	grid->attach(*previous,0,9,1,1);
	grid->attach(*next,1,9,1,1);
	grid->attach(*cancel,0,10,2,1);
	
	add(*grid);



}

AllAppsMenu::~AllAppsMenu(){
	delete(searchOptions);
	delete(searchWord);
	delete(appNumber);
	delete(stuNumber);
	delete(name);
	delete(previous);
	delete(next);
	delete(cancel);
	delete(search);
	delete(grid);
	delete(m_TextView);		
		
}
Gtk::TextView* AllAppsMenu::getTextView(){
	return m_TextView;

}
Gtk::Button* AllAppsMenu::getPrevious(){
	return previous;
}
Gtk::Button* AllAppsMenu::getNext(){
	return next;
}
Gtk::Button* AllAppsMenu::getCancel(){
	return cancel;
}
Gtk::Button* AllAppsMenu::getSearch(){
	return search;
}
Gtk::Grid* AllAppsMenu::getGrid(){
	return grid;
}

Gtk::RadioButton* AllAppsMenu:: getName(){
	return name;
}
Gtk::RadioButton* AllAppsMenu:: getAppNum(){
	return appNumber;
}
Gtk::RadioButton* AllAppsMenu:: getStuNum(){
	return stuNumber;
}

void AllAppsMenu::doSearch(){
	index = 0;
	total = 0;
	string line;
	stringstream output;
	ifstream myfile("saveLog.txt");
	while(getline(myfile,line)){
		istringstream toParse (line, istringstream::in);
		cout<<toParse.str()<<endl;
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
			//cout<<toParse.str()<<endl<<endl;
			if(symbol.compare("App") == 0)	{
				string appNum, status, course;
				getline(toParse, appNum, '$');
				getline(toParse, status,'$');
				getline(toParse,course,'$');			
					if( (searchCheck(appNum,stuNum,firstName,lastName)) && type.compare("Und") == 0 ){
						output<<"Applicant type: "<<"Undergraduate"<<endl;
						output<<"Name: "<<firstName<<" "<<lastName<<endl;
						output<<"Student Number: "<<stuNum<<endl;
						output<<"Email: "<<email<<endl;
						output<<"Major: "<<major<<endl;
						output<<"Year Standing: "<<standing<<endl;
						output<<"Cgpa: "<<cgpa<<endl;
						output<<"Gpa: "<<gpa<<endl;
						output<<"Applied to TA: "<<course<<endl;
						output<<"Application status: "<<status<<endl;
						getInfo(output,toParse);
						apps[index] = output.str();
						output.str("");
						output.clear();
						index++;
					}else if( (searchCheck(appNum,stuNum,firstName,lastName) ) && type.compare("Gra") == 0 ){
						output<<"Applicant type: "<<"Graduate"<<endl;
						output<<"Name: "<<firstName<<" "<<lastName<<endl;
						output<<"Student Number: "<<stuNum<<endl;
						output<<"Email: "<<email<<endl;
						output<<"Research Area: "<<research<<endl;
						output<<"Program: "<<program<<endl;
						output<<"Supervisor: "<<supervisor<<endl;
						output<<"Applied to TA: "<<course<<endl;
						output<<"Application status: "<<status<<endl;
						getInfo(output,toParse);
						apps[index] = output.str();
						output.str("");
						output.clear();
						index++;
					}
				}
		}		
	}

	total = index;
	index= 0;
	if(total == 0 ) m_refTextBuffer->set_text("NO applications found");
	else {
		setText();
		setControls();
	}

}
void AllAppsMenu::getInfo(stringstream& output, istringstream& toParse){
	string symbol="";
	while(getline(toParse,symbol,'$') ){
		if(symbol.compare("Ass")==0 ){
			string name, term, year, supervisor;
			getline(toParse,name,'$');
			getline(toParse,term,'$');
			getline(toParse,year,'$');
			getline(toParse,supervisor,'$');
			output<<endl<<" 	Previous Assisted Course"<<endl;
			output<<"Course name: "<<name<<endl;
			output<<"Course term: "<<term<<endl;
			output<<"Course year: "<<year<<endl;
			output<<"Course supervisor: "<<supervisor<<endl;
		}else if(symbol.compare("Rel")==0){
			string name, term, year, final;
			getline(toParse,name,'$');
			getline(toParse,term,'$');
			getline(toParse,year,'$');
			getline(toParse,final,'$');
			output<<endl<<"		 Previous Attended Course"<<endl;
			output<<"Course name: "<<name<<endl;
			output<<"Course term: "<<term<<endl;
			output<<"Course year: "<<year<<endl;
			output<<"Final grade: "<<final<<endl;
		}else if(symbol.compare("Wor")==0){
			string title, duration,start,end,duties;
			output<<endl<<"		Previous Work Experience :"<<endl;
			getline(toParse,title,'$');
			getline(toParse,duration,'$');
			getline(toParse,start,'$');
			getline(toParse,end,'$');
			getline(toParse,duties,'$');
			output<<"Job title: "<<title<<endl;
			output<<"Months at position: "<<duration<<"  From:  "<<start<<"  To:  "<<end<<endl;
			output<<"Position Duties: "<<duties<<endl;
		}else if( symbol.compare("App")==0){
			cout<<"parsing problem"<<endl;
			
		
		}
	}
	
}
void AllAppsMenu:: setControls(){
	next->set_sensitive(true);
	previous->set_sensitive(true);
	if(total <= 1){
		next->set_sensitive(false);
		previous->set_sensitive(false);
		return;
	}
	if(index +1 > total)next->set_sensitive(false);
	if(index -1 < 0)previous->set_sensitive(false);

}


bool AllAppsMenu:: searchCheck(string appNum,string stuNum,string firstName, string lastName){
	string keyword = searchTerm->get_text();
	if(appNumber->get_active()){
		if(keyword.compare(appNum)==0) return true;

	}else if(stuNumber->get_active()){
		if(keyword.compare(stuNum)==0) return true;

	}else if(name->get_active()){
		unsigned found = keyword.find(firstName);
		if(found != std::string::npos) return true;
		found = keyword.find(lastName);
		if(found != std::string::npos) return true;
	}
	return false;
}

void AllAppsMenu:: prevClicked(){
	if(index > 0 && total != 0) index--;
	setText();
	setControls();
}

void AllAppsMenu::nextClicked(){
	if(index+1 < total && total != 0 ) index++;
	setText();
	setControls();
}

void AllAppsMenu::clear(){
		m_refTextBuffer->set_text("");
		searchTerm->set_text("");
		

}

void AllAppsMenu::setText(){
	stringstream viewing;
	viewing <<" Viewing Application "<<index+1<<"/"<<total<<endl<<endl<<endl;
	viewing<<apps[index]<<endl;
	m_refTextBuffer->set_text(viewing.str());

}
