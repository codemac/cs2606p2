#include "System.h"

void System::run(const ostream& out) {
	///	set the BTree output streams
	keyword.setOut(out);
	cost.setOut(out);
	id.setOut(out);
	date.setOut(out);

	bool exit = false;
    string command = "";
    while ( !cin.eof() && !exit)
    {   
        getline(cin, command);
            cout << command << endl;
        istringstream stream (command);
        stream >> command;        
        if ( command == "insert" )
        {
            insert(bst, kdt, dataStorage, stream);
        }
        else if ( command == "delete" )
        {
            remove(bst, kdt, dataStorage, stream);
        }
        else if ( command == "info" )
        {
            info(bst, kdt, dataStorage, stream);
        }
        else if ( command == "search" )
        {
            search(kdt, stream);
        }
        else if ( command == "dump" )
        {
            bst.display(cout);
            kdt.display(cout);
        }
        else if ( command == "makenull" )
        {
            makenull(bst, kdt, dataStorage);
        }   
        else if ( command == "exit" || command == "quit" )
        {
        	exit = true;
        }
        else cout << "Unrecognized command.";
    }
}

