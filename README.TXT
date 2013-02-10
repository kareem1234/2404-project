To run program execute commands:
				make
				./Assignment1

Program will randomly create segmentation faults upon window exit. We thoroughly debugged our program and came up empty-handed. 
All our destructors were executed before the segmentation fault was issued. Thus were are stifled at where it is issuing from and
whether is may be from the library itself. Our program will create memory leaks due to gtkmm library, size of memory leak is 
dependant on amount of windows created. All memory explicitly is deallocated.
