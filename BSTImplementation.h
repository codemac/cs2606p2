/**
 * This the implementation of the Binary Search Tree that is implemtented 
 * in the following way: When a node is inserted or removed, we use a 
 * NodeStorage object to get/save nodes. 
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef BSTIMPLEMENTATION_H_
#define BSTIMPLEMENTATION_H_
#include<iomanip>
#include<iostream>
#include <cassert>
#include "Node.h"
#include "NodeStorage.h"
#include "DataHolder.h"
using namespace std;
// -------------------------------------------------------------------------
/**
 * Default constructor.  This creates the BST and initializes the NodeStorage.
 */
template <typename T>
BST<T>::BST()
{
    init();
}
/*
 * This is another constructor used when we already have a NodeStorage object.
 */
template <typename T>
BST<T>::BST(NodeStorage<T>* ns)
{
    count = 0;
    root = NULL;
    selfStorage = false;
    nodeStorage = ns;
}
// -------------------------------------------------------------------------
/**
 * Initiates and sets up all nodes and counts.
 */
 template <typename T>
 void BST<T>::init()
 {
 	count = 0;
 	root = NULL;
 	selfStorage = true;
 	nodeStorage = new NodeStorage<T>();
 }
// -------------------------------------------------------------------------
/**
 * The destructor for the BST. This will make sure we clean up our pointers.
 */
template <typename T>
BST<T>::~BST()
{
    clear();
    if ( selfStorage )
    {
    	delete nodeStorage;
    }
}
// -------------------------------------------------------------------------
/**
 * This method will allow us to add items to our tree.  If an item is less 
 * than it's parent, it is put to the left, other wise it goes to 
 * the right.
 * @param item - the item we want to store in our tree.
 */
template <typename T>
void BST<T>::add(T* item)
{
    root = addHelper(root, item);
    count++;
}
// -------------------------------------------------------------------------
/**
 * This is the private helper method for the add method where the actual
 * code implementation is.
 * @param item - the item we want to store in our tree
 * @param sroot - the current root of the tree
 * @return Node<T>* - returns a reference to our tree with the item stored
 */
template <typename T>
Node<T>* BST<T>::addHelper(Node<T>* sroot, T* item)
{
    if(sroot == NULL) //tree is empty
    {
    	sroot = nodeStorage->getMeANode();
    	sroot->data = item;	
    }
    else if ((*(sroot->data)).name < (*item).name) //goes to the right because the item passed in is >= ours
    {
    	sroot->right = addHelper(sroot->right, item);
    }
    else //goes to the left because the item passed in is < ours
    {
    	sroot->left = addHelper(sroot->left, item);
    }
    return sroot;
}
// -------------------------------------------------------------------------
/**
* This method will remove items from our tree.  Any item can be removed from
 * the tree, and the tree will be readjusted to fit the particular situation.
 * The remove method has a helper method which also has it's own helper method.
 * @param name - the name of the city store in the object we want to remove from our tree.
 */
template <typename T>
T* BST<T>::removeByName(string name)
{
	T* temp = NULL;
    root = removeHelper(root, name, temp);
	return temp;
}
// -------------------------------------------------------------------------
/**
* This is the private helper method for the remove method where the actual
 * code implementation is.
 * @param sroot - the root of the current tree
 * @param name - the name of the city to remove
 * @param data - the pointer to the object that is removed
 * @return Node<T>* - returns a pointer to the tree with the node now in NodeStorage
 */
template <typename T>
Node<T>* BST<T>::removeHelper(Node<T>* sroot, string name, T* &data)
{
 	if (sroot!= NULL)
 	{
 		if (sroot->data->name == name) //check current node
 		{
 			data = (sroot->data);
 			sroot = deleteNode(sroot);
 		}
 		else if (sroot->data->name <= name) //check right
 		{
 			sroot->right = removeHelper(sroot->right, name, data);
 		}
 		else //check left
 		{
 			sroot->left = removeHelper(sroot->left, name, data);
 		}
 	}
 	return sroot;
} 
// -------------------------------------------------------------------------
/**
 * This is a private helper method to help the removeHelper method.
 * It serves to delete the specified node from the tree and put it into NodeStorage.
 * @param sroot - the root of the current tree
 * @return Node<T>* - returns a reference to the current tree
 */
template <typename T>
Node<T>* BST<T>::deleteNode(Node<T> *sroot)
{
	if (sroot->right == NULL && sroot->left == NULL) //is a leaf
  	{
  		nodeStorage->add(sroot); 
  		sroot = NULL;
  		count--;
  	}
  	else if (sroot->left == NULL) //has 1 child on right
 	{
  		Node<T>* temp = sroot->right;
  		nodeStorage->add(sroot); 
  		sroot = temp;
  		count--;
 	}
 	else if (sroot->right == NULL) //has 1 child on left
 	{
  		Node<T>* temp = sroot->left;
  		nodeStorage->add(sroot); 
  		sroot = temp;
  		count--;
 	}
  	else //has two children
 	{
  		sroot->data = deleteNodeWithTwoKids(sroot);
 	}
  	return sroot;
}
// -------------------------------------------------------------------------
/**
* This is a private helper method to help the deleteNode method, it deletes a 
* node with two kids.
* @param sroot - the root of the current tree
* @return T* - returns a pointer the item we are deleting
*/
template <typename T>
T* BST<T>::deleteNodeWithTwoKids(Node<T>* sroot)
{
	Node<T>* prev = sroot;
	Node<T>* walker = sroot->right;
	while(walker->left != NULL)
	{
		prev = walker;
		walker = walker->left;
	}
	T* toReturn = walker->data;
	if (prev != sroot)
	{
		prev->right = deleteNode(walker);
	}
	else
	{
		prev->left = deleteNode(walker);
	}
	return toReturn;
}
// -------------------------------------------------------------------------
/**
* This displays all important information to know about the BST.
* @param out - the output stream to be used for displaying.
*/
template <typename T>
void BST<T>::display(ostream& out) const
{
  	out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	out << "DATA STRUCTURE: Binary Search Tree" << endl;
 	out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
 	out << "Elements In Tree: " << count << endl;;
 	out << "::Printout of Structure::" << endl;
  	displayHelper(root, out, 0);
}
// -------------------------------------------------------------------------
/**
* This is the private helper method for the display method where the 
* actual code implementation is.
* @param sroot - current root of the tree
* @param out - the otuput stream to be used for printing
* @param depth - how deep into the tree a node is
*/
template <typename T>
void BST<T>::displayHelper(Node<T>* sroot, ostream &out, int depth) const
{
  if(sroot!=NULL)
  {
  	for (int i = 0; i < depth; i++)
  	{
  		out << "+";
  	}
  	out << (*(sroot->data)).name << ": " << (*(sroot->data)).x << ", " << (*(sroot->data)).y << endl;
  	displayHelper(sroot->left, out, depth + 1);
    displayHelper(sroot->right, out, depth + 1);
  }
}
// -------------------------------------------------------------------------
/**
 * This will return the tree to post-construction state. All data will be 
 * removed from the tree.
 */
template <typename T>
void BST<T>::clear()
{
  clearHelper(root);
  root = NULL; 
}
// -------------------------------------------------------------------------
/**
 * This is the private helper method for the clear method where the 
 * actual code implementation is.
 * @param sroot - the current root of the tree
 */
template <typename T>
void BST<T>::clearHelper(Node<T>* sroot)
{
  	if (sroot!= NULL)
  	{
  		clearHelper(sroot->left);
  		clearHelper(sroot->right);
  	}
  	if (sroot!= NULL)
  	{
  		sroot->right = sroot->left = NULL;
  		nodeStorage->add(sroot);
  		count--;
  	}
}
// -------------------------------------------------------------------------
/**
 * This will return the number of nodes in the tree.
 * @return - the number of nodes in the tree.
 */
template <typename T>
int BST<T>::size() const
{
	return count;
}
#endif /*BSTIMPLEMENTATION_H_*/
