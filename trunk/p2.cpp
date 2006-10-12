/**
 * This is our driver class. It is in charge of parsing our input text.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#include "KDTree.h"
#include "BST.h"
#include "DataStorage.h"
#include "NodeStorage.h"
#include "DataHolder.h"
#include <string>
#include <sstream>

using namespace std;

/**
 * This method prints out information about a particular DataHolder object.
 * @param dh - the dataholder object to print info about.
 */
void print(DataHolder* dh)
{
    cout << "City: " << (*dh).name << "(" << dh->x << ", " << dh->y << ")" << endl;
}
/**
 * This method inserts given data into the trees.
 * @param stream - the stream with command parameters
 */
void insert(BST<DataHolder> &bst, KDTree<DataHolder, DataHolder::DataComparator> &kdt, DataStorage<DataHolder> &dataStorage, istringstream &stream)
{
    int x;
    int y;
    string name = "";
    stream >> x;
    stream >> y;
    stream >> name;

	DataHolder* data = dataStorage.getMeANode();
	(*data).x = x;
	(*data).y = y;
    (*data).name = name;
	if ( kdt.find(data) )
	{
		cout << "City with identical coordinates already exists." << endl;
		dataStorage.add(data);
		return;
	}
	if (x < 0 || x > 1023 || y < 0 || y > 1023)
	{
		cout << "Coordinates do not fit within designated interval." << endl;
		dataStorage.add(data);
		return;
	}
	cout << name << " inserted successfully." << endl;
	kdt.add(data);
	bst.add(data);	
}
/**
 * This method removes given data from the trees.
 * @param stream - the stream with command parameters
 */
void remove (BST<DataHolder> &bst, KDTree<DataHolder, DataHolder::DataComparator> &kdt, DataStorage<DataHolder> &dataStorage, istringstream &stream)
{
    int x;
	int y;
	string name = "";
    stream >> name;
    istringstream stemp(name);
    if (stemp >> x)
    {
        stream >> y;
        //know we have coords.
        DataHolder* temp = dataStorage.getMeANode();
        (*temp).x = x;
        (*temp).y = y;
        DataHolder* data = kdt.removeByCoords(temp);
        dataStorage.add(temp);
        temp = NULL;
        
        
        if ( data )
        {
            temp = bst.removeByName(data->name);
            while ( !(DataHolder::DataComparator::equals(data, temp)) ) 
            {
                bst.add(temp);
                temp = bst.removeByName(data->name);
                
            }
            dataStorage.add(data);
            cout << "Deleted." << endl;
        }
        else { cout << "City not found." << endl; }
    }
    else
    {
		DataHolder* data = bst.removeByName(name);
        kdt.removeByCoords(data);
        
        if ( !data )
        {
        	cout << "City not found." << endl;
        	return;
        }
        cout << "Deleted." << endl;
		while ( data )
		{
			dataStorage.add(data);
			data = bst.removeByName(name);
       		kdt.removeByCoords(data);
       		
		}
    }
}
/**
 * This method prints out info about a particular node.
 * @param stream - the stream with command parameters
 */
void info(BST<DataHolder> &bst, KDTree<DataHolder, DataHolder::DataComparator> &kdt, DataStorage<DataHolder> &dataStorage, istringstream &stream)
{
    int x;
    int y;
    string name = "";
    stream >> name;
    istringstream stemp(name);
    if (stemp >> x)
    {
        stream >> y;
        //know it's coords
        DataHolder* temp = dataStorage.getMeANode();
        (*temp).x = x;
        (*temp).y = y;
        DataHolder* data = kdt.removeByCoords(temp);
        dataStorage.add(temp);
        if ( data )
        {
            print(data);
            kdt.add(data);
        }
        else cout << "City not found." << endl;
    }
    else
    {
		DataHolder* data = bst.removeByName(name);
		DataHolder* temp = data;
		if ( data )
		{
			print(data);
			bst.add(data);
			data = bst.removeByName(name);
			while ( !DataHolder::DataComparator::equals(data, temp) )
			{
				print(data);
				bst.add(data);
				data = bst.removeByName(name);
			}
			bst.add(data);
		}
		else cout << "City not found." << endl;
	}	
}
/**
 * This method searches within the trees for nodes within a particular region.
 * @param stream - the stream with command parameters
 */
void search(KDTree<DataHolder, DataHolder::DataComparator> &kdt, istringstream &stream)
{
	long x,y,radius;
	stream >> x >> y >> radius;
	if (x <= -16384 || x >= 16384 || y <= -16384 || y >= 16384)
	{
		cout << "Coordinates do not fit within designated interval." << endl;
		return;
	}
	if (radius <= 0 || radius >= 16384)
	{
		cout << "Radius is invalid." << endl;
		return;
	}
		
	kdt.search(x, y, radius);
}
/**
 * This method clears the trees.
 */
void makenull(BST<DataHolder> &bst, KDTree<DataHolder, DataHolder::DataComparator> &kdt, DataStorage<DataHolder> &dataStorage)
{
	dataStorage.add(kdt.clear());
	bst.clear();
	cout << "Database now empty." << endl;
}

/**
 * This method parses and calls on commands. Compiler: g++  Operating system: WindowsXP
 * Date completed: 9.12.06
 * This program is used to store information about cities and their corresponding coordinates.
 * A BST is used to store the city names, and a KDTree is used to store the coordinate data.
 * The program allows you to insert information giving coordinates and city names, delete
 * cities given either a city name or coordinate data, and get info about cities given either
 * the city name or coordinate data.  It also allows you to search for cities within a certain
 * area, given coordinates for a center point and a radius.  The trees can also be printed and made null.
 */
int main ()
{
	System s;
	s.run();
	return 0;



	NodeStorage<DataHolder> *nodeStorage = new NodeStorage<DataHolder>(); //nodestorage pointer
	KDTree<DataHolder, DataHolder::DataComparator> kdt(2, nodeStorage); //KDTree
	BST<DataHolder> bst(nodeStorage);; //BST
	DataStorage<DataHolder> dataStorage; //DataStorage object
	
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
    makenull(bst, kdt, dataStorage);
    delete nodeStorage;
    return 0;
}
