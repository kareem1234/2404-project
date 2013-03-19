#include "AppListMenu.h"



AppListMenu :: AppListMenu(){

	grid = new Gtk::Grid();
	cancel = new Gtk::Button("CANCEL");
	select = new Gtk::Button("ASSIGN SUCCESFUL APPLICATION");
	select->set_sensitive(false);
	m_TreeView = new Gtk::TreeView;
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	m_TreeView->set_model(m_refTreeModel);
	m_ScrolledWindow.add(*m_TreeView);
	m_ScrolledWindow.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
	cancel->set_size_request(70,30);
    	select->set_size_request(70,30);
	m_ScrolledWindow.set_size_request(250,400);

	grid->attach(m_ScrolledWindow,0,0,2,3);
	grid->attach(*select,0,3,2,1);	
	grid->attach(*cancel,0,4,2,1);
	loadAppList();
	add(*grid);


}
AppListMenu::~AppListMenu()	{
	delete(grid);
	delete(cancel);
	delete(select);
	delete(m_TreeView);

}

void AppListMenu:: loadAppList(){
	ifstream myfile("saveLog.txt");
	string line;
	string trash,  status, firstname,  lastname, appNum, course;
	while(getline(myfile,line)){
		istringstream toParse (line, istringstream::in);
		getline(toParse,trash,'$');
		string symbol = "";
		getline(toParse,firstname,'$');
		cout<<firstname<<endl;
		getline(toParse,lastname,'$');
		while(getline(toParse,symbol,'$')){
			if(symbol.compare("App") == 0)	{
				getline(toParse, appNum, '$');
				getline(toParse, status,'$');
				getline(toParse,course,'$');
				if(status.compare("pending")== 0){
					string text = firstname+" "+ lastname+" "+appNum+" "+status+" "+course;
					Gtk::TreeModel::Row row = *(m_refTreeModel->append());
					row[m_Columns.m_col_name] = text;	
				}
			}
		}
	}
	m_TreeView->append_column("PENDING APPLICATION LIST", m_Columns.m_col_name);
}

void AppListMenu::editSaveLog(string app){
	ofstream toSave;
	toSave.open("newSaveLog.txt");
	ifstream myfile("saveLog.txt");
	string line;
	string newApp = app;
	size_t s = newApp.find("pending",0);
	newApp.replace(s,7,"assigned");
	while(getline(myfile,line)){
		size_t start = 0;
		if( (start = line.find(app,start)) != string::npos ){
			line.replace(start,app.length(),newApp);
			start= 0;
			while( (start = line.find("pending",start)) != string::npos ){
				line.replace(start,7,"closed");		
				start+=7;
			}
		}
	toSave<<line<<endl;
	}
	toSave.close();
	std::remove("saveLogt.txt");
	std::rename("newSaveLog.txt","saveLog.txt");
	


}
void AppListMenu::assignApp(){
	cout<<"have been called"<<endl;
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = m_TreeView->get_selection();
	Gtk::TreeModel::iterator iter = refTreeSelection->get_selected();
	if(iter)  {
  		Gtk::TreeModel::Row row = *iter;
		string s = row->get_value(m_Columns.m_col_name);
		stringstream editString(s);
		string appNum,trash,symbol,status,course;
		getline(editString,trash,' ');
		getline(editString,trash,' ');
		getline(editString,appNum,' ');
		getline(editString,status,' ');
		getline(editString,course,' ');
		string output =appNum+'$'+status+'$'+course;
		editSaveLog(output);
	}


}
Gtk::Grid* AppListMenu::getGrid()  {
	return grid;
}

//Returns cancel button when called
Gtk::Button* AppListMenu::getCancel(){
	return cancel;
}


//Returns select button when called
Gtk::Button* AppListMenu::getSelect(){
	return select;
}
Gtk::TreeView* AppListMenu::getTreeView(){
	return m_TreeView;
}



