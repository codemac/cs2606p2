#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>

using namespace std;

/**
 * This class takes stdin, and gives back an array of strings in a pointer
 * so that some other interpreter class can take the tokenized results and 
 * perform some function on them
 */
class Parser
{
	private:
		istream in;

	public:
		Parser(const istream &in);
		Parser();
		~Parser();
};

/******************************  code from old main.cpp to use for command parsing
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
	*/
#endif
