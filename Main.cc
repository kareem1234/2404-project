//Main source file

#include "Main.h"

int main(int argc, char *argv[])	{
	
	Gtk::Main kit(argc, argv);

  	Controller control;

  	Gtk::Main::run(control);

	return 0;
}
