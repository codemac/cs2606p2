/**
 * We will be using this class to handle 
 * the adding and removing of nodes from the BST and KDTree.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef NODESTORAGEIMPLEMENTATION_H_
#define NODESTORAGEIMPLEMENTATION_H_
#include "Node.h"
#include <iostream>

// -------------------------------------------------------------------------
/**
 * Default constructor.  This creates the NodeStorage object and initializes
 * private variables.
 */
template <typename T>
NodeStorage<T>::NodeStorage()
{
	head = new Node<T>();
}
// -------------------------------------------------------------------------
/**
 * This is the destructor that takes care of deleting the nodes in our storage.
 */
template <typename T>
NodeStorage<T>::~NodeStorage()
{	
	clear(head);
}

template <typename T>
void NodeStorage<T>::clear(Node<T>* node)
{
	if (node)
	{
		if (node->right) 
		{ 
			clear(node->right); 
		}
		delete node;
	}
	
}
// -------------------------------------------------------------------------
/**
* This method will allow us to add a Node<T>* to our nodestorage.
* @param theNode - A pointer to a Node<T>
*/
template <typename T>
void NodeStorage<T>::add(Node<T>* theNode)
{
 	theNode->right = head->right;
 	head->right = theNode;
    theNode->left = NULL;
}
// -------------------------------------------------------------------------
/**
* This method will tell if there are nodes in storage.
* @return - true if there are more nodes in storage and false otherwise
*/
template <typename T>
bool NodeStorage<T>::gotAnyNodes() const
{
    return (head->right != NULL);
}
// --------------------------------------------------------------------------
/**
* This will return the next node in the storage object.  If the NodeStorage
* is empty, then it returns a NULL pointer.
* @return - the next Node<T>* in the storage
*/
template <typename T>
Node<T>* NodeStorage<T>::getMeANode()
{
	if (!gotAnyNodes()) //there are no nodes in storage
	{
		Node<T>* temp = new Node<T>();
		return temp;
	}
	else //there are nodes in storage
	{
		Node<T>* temp = head->right;
		head->right = head->right->right;
		temp->right = NULL;
		return temp;
	}
}
#endif /*NODESTORAGEIMPLEMENTATION_H_*/
