/**
 * We will be using this class to handle 
 * the adding and removing of nodes from the BST and KDTree.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef NODESTORAGE_H_
#define NODESTORAGE_H_
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class NodeStorage
{
	private:
		//This is the private variable:
		Node<T>* head; //pointer to the head of the linked list
		/**
		 * Helper method for the deconstructor.
		 * @param node - the node and its children to be deleted
		 */
		void clear(Node<T>* node); 
	public:
		
		//These are the public method.
		/**
 		* Default constructor.  This creates the NodeStorage object and initializes
 		* private variables.
 		*/
		NodeStorage();
		/**
 		* This is the destructor that takes care of deleting the nodes in our storage.
 		*/
		 ~NodeStorage();
		/**
		* This method will allow us to add a Node<T>* to our nodestorage.
 		* @param theNode - A pointer to a Node<T>
		*/
		 void add (Node<T> *theNode);
		/**
 		* This method will tell if there are nodes in storage.
 		* @return - true if there are more nodes in storage and false otherwise
 		*/
		 bool gotAnyNodes() const;
		/**
 		* This will return the next node in the storage object.  If the NodeStorage
 		* is empty, then it returns a NULL pointer.
 		* @return - the next Node<T>* in the storage
 		*/
		 Node<T>* getMeANode();
};		
#include "NodeStorageImplementation.h"
#endif /*NODESTORAGE_H_*/
