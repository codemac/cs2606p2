/**
 * This is a Binary Search Tree that is implemtented in the following way:
 * When a node is inserted or removed, we use a NodeStorage object 
 * to get/save nodes.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef BST_H_
#define BST_H_
#include "Node.h"
#include "NodeStorage.h"
#include <iostream>
using namespace std;

template <typename T>
class BST
{
	private:
		
		//These are the private variables.
		NodeStorage<T>* nodeStorage; //nodestorage variable
		Node<T>* root; //points to the root of the tree
		int count; //keeps track of the number of data items in the tree
		bool selfStorage; //true if the bst made it's own nodestorage variable
		
		//These are the private methods. 
		/**
 		* Initiates and sets up all nodes and counts.
 		*/
		void init();
		/**
 		* This is the private helper method for the add method where the actual
 		* code implementation is.
 		* @param item - the item we want to store in our tree
 		* @param sroot - the current root of the tree
 		* @return Node<T>* - returns a reference to our tree with the item stored
 		*/
		Node<T>* addHelper(Node<T>* sroot, T* item);
		/**
		* This is the private helper method for the remove method where the actual
 		* code implementation is.
 		* @param sroot - the root of the current tree
 		* @param name - the name of the city to remove
 		* @param data - the pointer to the object that is removed
 		* @return Node<T>* - returns a pointer to the tree with the node now in NodeStorage
 		*/
		Node<T>* removeHelper(Node<T>* sroot, string name, T* &data);
		/**
 		* This is a private helper method to help the removeHelper method.
 		* It serves to delete the specified node from the tree and put it into NodeStorage.
 		* @param sroot - the root of the current tree
 		* @return Node<T>* - returns a reference to the current tree
 		*/
		Node<T>* deleteNode(Node<T> *sroot);
		/**
 		* This is a private helper method to help the deleteNode method, it deletes a 
 		* node with two kids.
 		* @param sroot - the root of the current tree
 		* @return T* - returns a pointer the item we are deleting
 		*/
		T* deleteNodeWithTwoKids(Node<T>* sroot);
		/**
		 * This is the private helper method for the display method where the 
 		* actual code implementation is.
 		* @param sroot - current root of the tree
 		* @param out - the otuput stream to be used for printing
 		* @param depth - how deep into the tree a node is
 		*/
		void displayHelper(Node<T>* sroot, ostream &out, int depth) const;
		/**
 		* This is the private helper method for the clear method where the 
 		* actual code implementation is.
 		* @param sroot - the current root of the tree
 		*/
		void clearHelper(Node<T>* sroot);
		/**
		 * Keeps nodes within the system of these classes
		 */
		friend class NodeStorage<T>;
		friend class Node<T>;
	public:
		
		//These are the public methods.
		/**
 		* Default constructor.  This creates the BST and initializes the NodeStorage.
 		*/
		BST();
		/**
		 * This is another constructor used when we already have a NodeStorage object.
         */
        BST(NodeStorage<T>* ns);
		/**
 		* The destructor for the BST. This will make sure we clean up our pointers.
 		*/
		virtual ~BST();
		/**
 		* This method will allow us to add items to our tree.  If an item is less 
 		* than it's parent, it is put to the left, other wise it goes to 
 		* the right.
 		* @param item - the item we want to store in our tree.
 		*/
 		virtual void add(T* item);	
		/**
		* This method will remove items from our tree.  Any item can be removed from
 		* the tree, and the tree will be readjusted to fit the particular situation.
 		* The remove method has a helper method which also has it's own helper method.
 		* @param name - the name of the city store in the object we want to remove from our tree.
 		*/
		virtual T* removeByName(string name);
		/**
		* This displays all important information to know about the BST.
 		* @param out - the output stream to be used for displaying.
 		*/
		virtual void display(ostream &out) const;
		/**
 		* This will return the tree to post-construction state. All data will be 
 		* removed from the tree.
 		*/
		virtual void clear();
		/**
 		* This will return the number of nodes in the tree.
 		* @return - the number of nodes in the tree.
 		*/
		virtual int size() const;		
};
#include "BSTImplementation.h"
	
#endif /*BST_H_*/
