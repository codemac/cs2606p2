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
			int id;
			cin >> id;
			r->id(id);

			string title;
			cin.getline(title, 100);
			r->title(title);

			cin.getline(title, 100);
			istringstream stream(title);
			int date;
			stream >> date;
			r->date(date);

			int length;
			stream >> length;
			r->length(length);

			int x,y;
			stream >> x >> y;
			r->x(x);	r->y(y);

			int cost;
			stream >> cost;
			r->cost(cost);

			while (cin.peek() != '\n')
			{
				cin >> title;
				r->keywords(title);
			}
			//	Description insert goes here.
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
				Record* o = new Record();
				while ( cin.peek() != '\n' )
				{
					cin >> command;
					o->keywords(command);
				}
				keyword.search(o,cout);
					
			}
			else if ( command == "location" )
			{
				unsigned short int x, y;
				cin >> x >> y;
				Record *o1 = new Record();
				o1->x(x);
				o1->y(y);
				location.search(o1,cout);
			}
			else if ( command == "cost" )
			{
				int low, high;
				cin >> low >> high;
				Record *o1 = new Record();
				Record *o2 = new Record();
				o1->cost(low);
				o2->cost(high);
				cost.search(o1,o2,cout);
			}
        }
        else if ( command == "dump" )
        {
            cin >> command;
			if ( command == "date" ) date.dump();
			else if ( command == "keyword" ) keyword.dump();
			else if ( command == "location" ) location.dump();
			else if ( command == "cost" ) cost.dump();
			else if ( command == "ID" ) id.dump();
			else cout << "Invalid command" << endl;
        }
        else if ( command == "exit" || command == "quit" )
        {
        	exit = true;
        }
        else cout << "Unrecognized command.";
    }
}

