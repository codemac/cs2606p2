/**
 * This class stores unused DataHolder objects.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef DATASTORAGEIMPLEMENTATION_H_
#define DATASTORAGEIMPLEMENTATION_H_
#include "DataHolder.h"
#include <iostream>
// -------------------------------------------------------------------------
/**
* Default constructor.  This creates the DataStorage object and initializes
* private variables.
*/
template <typename T>
DataStorage<T>::DataStorage()
{
	head = new T();
}
// -------------------------------------------------------------------------
/**
* This is the destructor that takes care of deleting the nodes in our storage.
*/
template <typename T>
DataStorage<T>::~DataStorage()
{	
	while (gotAnyNodes())
	{
		T* temp = getMeANode();
		delete temp;
	}
	
	delete head;
}
// -------------------------------------------------------------------------
/**
* This method will allow us to add a DataHolder object to our DataStorage.
* @param theNode - A pointer to a DataHolder object
*/
template <typename T>
void DataStorage<T>::add(T* theNode)
{
	if ( theNode )
	{
		T* temp = theNode;
		while ( temp->next )
		{
			temp = temp->next;
		}
	 	temp->next = head->next;
	 	head->next = theNode;
	}
}
// -------------------------------------------------------------------------
/**
* This method will tell if there are any nodes in storage.
* @return - true if there are more nodes in starage and false otherwise
*/
template <typename T>
bool DataStorage<T>::gotAnyNodes() const
{
    return (head->next != NULL);
}
// --------------------------------------------------------------------------
/**
* This will return the next node in the storage object.  If the DataStorage
* is empty, then it returns a new DataHolder object.
* @return - the next DataHolder object in storage
*/
template <typename T>
T* DataStorage<T>::getMeANode()
{
	if (!gotAnyNodes()) //there are no nodes in storage
	{
		T* temp = new T();
		return temp;
	}
	else //there are nodes in storage
	{
		T* temp = head->next;
		head->next = head->next->next;
		temp->next = NULL;
		return temp;
	}
}
#endif /*DATASTORAGEIMPLEMENTATION_H_*/
