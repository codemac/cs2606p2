/**
 * This is the node class. It is used by the KDTree and the BST.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef NODE_H_
#define NODE_H_

template <typename T>
class Node
{
	public:
	
		//These are the public variables.
		T* data; //the data in the item
		Node<T>* left; //pointer to the left child
		Node<T>* right; //pointer to the right child
		Node<T>(); //constructor
		virtual ~Node<T>(); //destructor
// -------------------------------------------------------------------------
/**
 * This constructor takes in an item along with the option of a rightvalue
 * and a leftvalue.
 * @param item - the item to store in the node
 * @param rightval - the value of the right child's node
 * @param leftval - the value of the left child's node
 */
	Node<T>(T* item, Node<T> *rightval, Node<T> *leftval);
// -------------------------------------------------------------------------
/**
 * This constructor takes in a rightvalue and a leftvalue.
 * @param rightval - the value of the right child's node
 * @param leftval - the value of the left child's node
 */		
 	Node<T>(Node<T> *rightval, Node<T> *leftval);
};
#include "NodeImplementation.h"
#endif /*NODE_H_*/
