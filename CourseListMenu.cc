//CourseListMenu source file

//Include statements
#include "CourseListMenu.h"
using namespace std;

#include <fstream>
#include <cstdlib>

//Default constructor
CourseListMenu::CourseListMenu(int Type){
	type = Type;
	grid = new Gtk::Grid();
	cancel = new Gtk::Button("CANCEL");
	skip = new Gtk::Button("SKIP");
	select= new Gtk::Button("SELECT");
	select->set_sensitive(false);
	m_TreeView = new Gtk::TreeView;
	m_TextView = new Gtk::TextView;
	
	//Make scrolling view
	m_ScrolledWindow.add(*m_TreeView);
	m_ScrolledWindow.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
		
	//Depending on the type the list looks different and has different behaviour
	if(type == 1){
		m_ScrolledWindow2.add(*m_TextView);
		m_TextView->set_editable(false);
		m_ScrolledWindow2.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
		m_refTextBuffer = Gtk::TextBuffer::create();
		m_TextView->set_buffer(m_refTextBuffer);
		m_ScrolledWindow2.set_size_request(80,200);
	}

	cancel->set_size_request(70,30);
    	select->set_size_request(70,30);
	skip->set_size_request(70,30);
	m_ScrolledWindow.set_size_request(250,400);

	if(type == 0){
		grid->attach(m_ScrolledWindow,0,0,2,3);
		grid->attach(*select,0,3,2,1);	
		grid->attach(*cancel,0,4,2,1);
	}else if(type == 1){
		grid->attach(m_ScrolledWindow,0,0,2,2);
		grid->attach(m_ScrolledWindow2,0,2,3,3);
		grid->attach(*select,0,5,2,1);		
		grid->attach(*cancel,0,6,2,1);
	} else if (type == 3 || type == 4)	{
		grid->attach(m_ScrolledWindow,0,0,2,3);
		grid->attach(*select,0,3,2,1);
		grid->attach(*skip,0,4,2,1);
	}

	//Setup courseList
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	m_TreeView->set_model(m_refTreeModel);
	loadCourseList();
	if(type == 3)	m_TreeView->append_column("RELATED COURSE", m_Columns.m_col_name);
	else if (type == 4)	m_TreeView->append_column("TA COURSE LIST", m_Columns.m_col_name);
	else	m_TreeView->append_column("COURSE LIST", m_Columns.m_col_name);

	add(*grid);
}

//Default destructor
CourseListMenu::~CourseListMenu()	{

	delete(grid);
	delete(cancel);
	delete(skip);
	delete(select);
	delete(m_TreeView);
	delete(m_TextView);

}

//Returns int type describing what list it is
int CourseListMenu::getType(){
	return type;
}

//Loads list of courses into GUI list
int CourseListMenu::loadCourseList(){
	
	ifstream loadFile("courseList.txt", ios::in);
	
	if(!loadFile){
		return 0;
	}
	
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	char line[50];
	// getting lines from file
	while(!loadFile.eof()){
		loadFile.getline(line,50);
		row[m_Columns.m_col_name] = line;	
		row = *(m_refTreeModel->append());
	}

	return 1;
}

//Finds applications
void CourseListMenu:: findApp(){
	string line;
	stringstream output;
	stringstream newOutput;
	bool found = false;
	int totalApps = 0;

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
			if(course.compare(getString()) == 0){
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
				totalApps++;
			
			}	
		}
	}
	if(found){
		if(totalApps == 1 ){
			setString(output.str());
			return;
		}else{
			int length = 9*totalApps;
			string toSort[length];
			int    pos = 0;
			int    intSort[totalApps];
			//int count = 0;
			for(int i=0;i<length;i++){
				getline(output,toSort[i],'\n');	
				// extract gpa's
				if(toSort[i].at(0) =='G'){
					istringstream buffer(toSort[i]);
					buffer>>intSort[pos];
					pos++;
				}
			}
			// loop through intSort
			bool done = false;
			while(done == false){
				done = true;
				int highest= -1;
				int index = -1;
				for(int i = 0; i<pos; i++){
					if(intSort[i] != -1 && intSort[i] >= highest){
						highest = intSort[i];
						index = i;
						//intSort[i]=-1;
						done = false;
					}
				}
				if(!done){
					intSort[index] = -1;
					//find the associated gpa and send it to the new output buffer				
					int start = index*9;
					int stop = start+9;
					for(start;start<stop;start++){
						newOutput<<toSort[start]<<endl;						
						
						
					}					
				}				
			}
			setString(newOutput.str());
		}







	}	
	else		setString("NO APPLICATION FOUND");
}

//Returns frame when called
Gtk::Grid* CourseListMenu::getGrid()  {
	return grid;
}

//Returns cancel button when called
Gtk::Button* CourseListMenu::getCancel(){
	return cancel;
}

//Returns skip button when called
Gtk::Button* CourseListMenu::getSkip()	{
	return skip;
}

//Returns select button when called
Gtk::Button* CourseListMenu::getSelect(){
	return select;
}

//Returns the current selection
string CourseListMenu::getString(){
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = m_TreeView->get_selection();
	Gtk::TreeModel::iterator iter = refTreeSelection->get_selected();
	if(iter)  {
  		Gtk::TreeModel::Row row = *iter;
		string s = row->get_value(m_Columns.m_col_name);
		return s;
	}
}

//Sets the courseList textfield if visible
void CourseListMenu::setString(string app){
	m_refTextBuffer->set_text(app);

}

//Returns the tree view
Gtk::TreeView* CourseListMenu::getTreeView(){
	return m_TreeView;
}

