#include "System.h"

void System::run(const ostream& out) {
	///	set the BTree output streams
	keyword.setOut(out);
	cost.setOut(out);
	id.setOut(out);
	date.setOut(out);
	//	KDTree location

	bool exit = false;
    string command = "";
    while ( !cin.eof() && !exit)
    {   
        cin >> command;
        cout << command << endl;        
        if ( command == "insert" )
        {
            
			Record* r = new Record();

        }
        else if ( command == "delete" )
        {
			//	NOT IMPLEMENTED
            //remove(bst, kdt, dataStorage, stream);
        }
        else if ( command == "search" )
        {
			cin >> command;
			if ( command == "date" )
			{
				int d1,d2;
				Record* o1 = new Record();
				Record* o2 = new Record();
				cin >> d1 >> d2;
				o1->date(d1);
				o2->date(d2);
				date.search(o1,o2,cout);
			}
			else if ( command == "keyword" )
			{
				
			}
			else if ( command == "location" )
			{
				unsigned short int x, y;
				cin >> x >> y;
				Record *o1 = new Record();
				o1->x(x);
				o1->y(y);
				kdtree.insert(o1);
			}
			else if ( command == "cost" )
			{

			}
        }
        else if ( command == "dump" )
        {
            bst.display(cout);
            kdt.display(cout);
        }
        else if ( command == "exit" || command == "quit" )
        {
        	exit = true;
        }
        else cout << "Unrecognized command.";
    }
}

