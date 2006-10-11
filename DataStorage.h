/**
 * This class stores unused DataHolder objects.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef DATASTORAGE_H_
#define DATASTORAGE_H_
#include "DataHolder.h"
#include <iostream>
using namespace std;

template <typename T>
class DataStorage
{
	private:	
		//This is the private variable:
		T* head; //pointer to the head of the linked list
	public:
		
		//These are the public method.
		/**
 		* Default constructor.  This creates the DataStorage object and initializes
 		* private variables.
 		*/
		DataStorage();
		/**
 		* This is the destructor that takes care of deleting the nodes in our storage.
 		*/
		~DataStorage();
		/**
		* This method will allow us to add a DataHolder object to our DataStorage.
 		* @param theNode - A pointer to a DataHolder object
		*/
		void add (T *theNode);
		/**
 		* This method will tell if there are any nodes in storage.
 		* @return - true if there are more nodes in starage and false otherwise
 		*/
		bool gotAnyNodes() const;
		/**
 		* This will return the next node in the storage object.  If the DataStorage
 		* is empty, then it returns a new DataHolder object.
 		* @return - the next DataHolder object in storage
 		*/
		T* getMeANode();
};		
#include "DataStorageImplementation.h"
#endif /*DATASTORAGE_H_*/
