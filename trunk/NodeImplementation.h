/**
 * This is the node class. It is used by the KDTree and the BST.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef NODEIMPLEMENTATION_H_
#define NODEIMPLEMENTATION_H_
/**
 * Default constructor.
 */
template <typename T>
Node<T>::Node<T>()
{
	data = 0;
	right = 0;
	left = 0;	
}
/**
 * Destructor.
 */
template <typename T>
Node<T>::~Node<T>()
{
}
// -------------------------------------------------------------------------
/**
 * This constructor takes in an item along with the option of a rightvalue
 * and a leftvalue.
 * @param item - the item to store in the node
 * @param rightval - the value of the right child's node
 * @param leftval - the value of the left child's node
 */
template <typename T>
Node<T>::Node<T>(T* item, Node<T> *rightval, Node<T> *leftval)
{
	data = item;
	right = rightval;
	left = leftval;
}
// -------------------------------------------------------------------------
/**
 * This constructor takes in a rightvalue and a leftvalue.
 * @param rightval - the value of the right child's node
 * @param leftval - the value of the left child's node
 */		
template <typename T>
Node<T>::Node<T>(Node<T> *rightval, Node<T> *leftval)
{
	right = rightval;
	left = leftval;
}

#endif /*NODEIMPLEMENTATION_H_*/
