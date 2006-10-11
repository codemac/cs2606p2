/**
 * This is a KD Tree that is implemtented in the following way:
 * When a node is inserted or removed, we use a NodeStorage object
 *  to get/save nodes. There is also a key value for each level of the tree.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef KDTREEIMPLEMENTATION_H_
#define KDTREEIMPLEMENTATION_H_
#include<iomanip>
#include<iostream>
#include <cassert>
#include "Node.h"
#include "NodeStorage.h"
#include "DataHolder.h"
using namespace std;

// -------------------------------------------------------------------------
/**
* Default constructor.  This creates the KDTree given the number of keys
* and initializes the NodeStorage.
*/
template <typename T, typename Comp>
KDTree<T, Comp>::KDTree(int num)
{
    init(num);
}
/**
 * This constructor creates the KDTree given the number of keys and a 
 * NodeStorage object.
 */
template <typename T, typename Comp>
KDTree<T, Comp>::KDTree(int num, NodeStorage<T>* ns)
{
    nodeStorage = ns;
    count = 0;
    selfStorage = false;
    root = NULL;
    numKeys = num;
}
// -------------------------------------------------------------------------
/**
 * Initiates and sets up all nodes and counts.
 */
 template <typename T, typename Comp>
 void KDTree<T, Comp>::init(int num)
 {
 	count = 0;
 	root = NULL;
 	selfStorage = true;
 	nodeStorage = new NodeStorage<T>();
 	numKeys = num;
 }
// -------------------------------------------------------------------------
/**
 * The destructor for the KDTree. This will make sure we clean up our pointers.
 */
template <typename T, typename Comp>
KDTree<T, Comp>::~KDTree()
{
    clear();
    if ( selfStorage )
    {
    	delete nodeStorage;
    }
}
// -------------------------------------------------------------------------
/**
 * This method will allow us to add items to our tree.  If an item is less than
 * it's parent,based on the descriminant at that level, it is put to the left, 
 * otherwise it goes to the right.
 * @param item - the item we want to store in our tree.
 */
template <typename T, typename Comp>
void KDTree<T, Comp>::add(T* item)
{
    root = addHelper(root, item, 0);
    count++;
}
// -------------------------------------------------------------------------
/**
* This is the private helper method for the add method where the actual
* code implementation is.
* @param item - the item we want to store in our tree
* @param sroot - the current root of the tree
* @param level - the level of the tree we are currently on, with the root
* level being defined as 0
* @return Node<T>* - returns a pointer to our tree with the item stored
*/
template <typename T, typename Comp>
Node<T>* KDTree<T, Comp>::addHelper(Node<T>* sroot, T* item, int level)
{
    if(sroot == NULL) //tree is empty
    {
    	sroot = nodeStorage->getMeANode();
    	sroot->data = item;	
    }
    else if ( Comp::gte(item, sroot->data, level%numKeys) ) //goes to the right because the item passed in is >= ours
    {
    	sroot->right = addHelper(sroot->right, item, level+1);
    }
    else //goes to the left because the item passed in is < ours
    {
    	sroot->left = addHelper(sroot->left, item, level+1);
    }
    return sroot;
}
/**
 * This is the search method that finds all of the nodes within the circle
 * created by the given center and radius.
 * @param x - the x coordinate of the center of the circle
 * @param y - the y coordinate of the center of the circle
 * @param radius - the radius of the circle
 */
template <typename T, typename Comp>
void KDTree<T, Comp>::search(long x, long y, long radius)
{
	int numNodes = searchHelper(root, x, y, radius, 0);
	cout << "Number of nodes visited: " << numNodes << endl;
}
/**
 * This is the helper method for the search method.
 * @param sroot - the current root of the tree
 * @param x - the x coordinate
 * @param y - the y coordinate
 * @param radius - the radius to use in our search
 * @param level - the current level
 * @return int - returns the number of nodes visited.
 */
template <typename T, typename Comp>
int KDTree<T, Comp>::searchHelper(Node<T>* sroot, long x, long y, long radius, int level)
{
	if ( sroot != NULL )
	{
		if ( radius*radius >= (((sroot->data->x-x)*(sroot->data->x-x))
								+((sroot->data->y-y)*(sroot->data->y-y))) )
		{
			cout << "City: " << sroot->data->name << " (" << sroot->data->x << ", " << sroot->data->y << ")" << endl;
		}
			
		if ( Comp::gte(x+radius, y+radius, sroot->data, level%numKeys) && sroot->right ) //goes to the right because the item passed in is >= ours
  		{
  			if ( Comp::lte(x-radius, y-radius, sroot->data, level%numKeys) && sroot->left )
  			{
    			return 1 + searchHelper(sroot->right, x, y, radius, level+1)
    					 + searchHelper(sroot->left, x, y, radius, level+1);
  			}
			else
			{
				return 1 + searchHelper(sroot->right, x, y, radius, level+1);
			}
		}
		else if ( sroot->left )
		{
			return 1 + searchHelper(sroot->left, x, y, radius, level+1);
		}
	}	
	return 1;
}
// -------------------------------------------------------------------------
/**
* This method will remove items from our tree.  Any item can be removed from
* the tree, and the tree will be readjusted to fit the particular situation.
* The remove method has a helper method which also has it's own helper method.
* @param removeMe - the item we want to remove from our tree.  Used over (int,int)
* so that the KD Tree stays generic in how many keys it has.
* @return T* - the data object removed
*/
template <typename T, typename Comp>
T* KDTree<T, Comp>::removeByCoords(T* removeMe)
{
	T* temp = NULL;
	
	if ( removeMe )
	{
		root = removeHelper(root, removeMe, temp, 0);
	}
	
	return temp;
}
// -------------------------------------------------------------------------
/**
* This is the private helper method for the remove method where the actual
* code implementation is.
* @param sroot - the root of the current tree
* @param removeMe - the item we want to remove from our tree.  
* Used over (int,int) so that the KD Tree stays generic in how many keys it has.
* @param data - the item removed
* @param level - the level of the tree we are currently on, with the root
* level being defined as 0
* @return Node<T>* - returns a reference to the tree with the item removed
*/
template <typename T, typename Comp>
Node<T>* KDTree<T, Comp>::removeHelper(Node<T>* sroot, T* removeMe, T* &data, int level)
{
 	if (sroot!= NULL)
 	{
 		if ( Comp::equals(sroot->data, removeMe) ) //check current node
 		{
 			data = sroot->data;
 			sroot = deleteNode(sroot, level);
 		}
 		else if ( Comp::gte(removeMe, sroot->data, level%numKeys) ) //check right
 		{
 			sroot->right = removeHelper(sroot->right, removeMe, data, level+1);
 		}
 		else //check left
 		{
 			sroot->left = removeHelper(sroot->left, removeMe, data, level+1);
 		}
 	}
 	return sroot;
}
/**
 * This is the find method that finds the given object in the tree, if it is there.
 * @param data - the object to find
 * @return bool - returns true if the object is found, otherwise returns false.
 */
template <typename T, typename Comp>
bool KDTree<T, Comp>::find(T* data)
{
	return findHelper(root, data, 0);
}
/**
 * This is the helper method for the find method.
 * @param sroot - the current root of the tree
 * @param data - the object to find
 * @param level - the current level
 * @return bool - returns true if the object is found, otherwise
 * returns false.
 */
template <typename T, typename Comp>
bool KDTree<T, Comp>::findHelper(Node<T>* sroot, T* data, int level)
{
 	if (sroot!= NULL)
 	{
 		if ( Comp::equals(sroot->data, data) ) //check current node
 		{
 			return true;
 		}
 		else if ( Comp::gte(data, sroot->data, level%numKeys) ) //check right
 		{
 			return findHelper(sroot->right, data, level+1);
 		}
 		else //check left
 		{
 			return findHelper(sroot->left, data, level+1);
 		}
 	}
 	return false;
}
// -------------------------------------------------------------------------
/**
* This is a private helper method to help the removeHelper method.
* It serves to delete the specified node.
* @param sroot - the root of the current tree
* @return Node<T>* - returns a reference to the current tree
*/
template <typename T, typename Comp>
Node<T>* KDTree<T, Comp>::deleteNode(Node<T> *sroot, int level)
{
	if (sroot->right == NULL && sroot->left == NULL) //is a leaf, delete it
  	{
  		nodeStorage->add(sroot); 
  		sroot = NULL;
  		count--;
  		return sroot;
  	}
  	else if (sroot->right == NULL) //has 1 subtree on left, make it a right subtree
 	{		
		sroot->right = sroot->left;
		sroot->left = NULL;
 	}
 	//has 1 subtree on right or two subtrees, find minimum in right subtree and swap
 	Node<T>* temp = findMin(sroot->right, level%numKeys); //change to sroot?
	swap(sroot, temp);
	Node<T>* tempParent = findParent(sroot, temp);
	if (tempParent->right == temp)
	{
		tempParent->right = deleteNode(temp, findLevel(root, temp, 0));
	}
	else
	{
		tempParent->left = deleteNode(temp, findLevel(root, temp, 0));
	}
	return sroot;
}
/**
 * This method finds the parent of the given node. If the given node
 * is the root of the tree, it returns NULL.
 * @param sroot - the current root of the tree
 * @param child - the node to find the parent of
 * @return Node<T>* - the parent of child
 */
template <typename T, typename Comp>
Node<T>* KDTree<T, Comp>::findParent(Node<T>* sroot, Node<T>* child)
{
	Node<T>* temp;
	if (sroot!= NULL)
	{
		if (sroot->right == child || sroot->left == child)
		{
			return sroot;
		}
		temp = findParent(sroot->right, child);
		if (temp)
		{
			return temp;
		}
		else
		{
			return findParent(sroot->left, child);
		}
	}
	return NULL;
}
/**
 * Finds the level of the given node.
 * @param sroot - the current root of the tree
 * @param findMe - the node to find the level of
 * @param level - the level we are currently on
 * @return int - the level of findMe
 */
template <typename T, typename Comp>
int KDTree<T, Comp>::findLevel(Node<T>* sroot, Node<T>* findMe, int level)
{
	if (sroot!= NULL)
 	{
 		if ( Comp::equals(sroot->data, findMe->data) ) //check current node
 		{
 			return 0;
 		}
 		else if ( Comp::gte(findMe->data, sroot->data, level%numKeys) ) //check right
 		{
 			return 1 + findLevel(sroot->right, findMe, level+1);
 		}
 		else //check left
 		{
 			return 1 + findLevel(sroot->left, findMe, level+1);
 		}
 	}
 	return -1; //nothing in the tree or not found
}
/**
 * Swaps the data holders of two nodes.
 * @param one - the node to swap with two
 * @param two - the node to swap with one
 */
template <typename T, typename Comp>
void KDTree<T, Comp>::swap(Node<T> *one, Node<T>* two)
{
	T* temp = one->data;
	one->data = two->data;
	two->data = temp;
}
/**
 * This finds the smallest root in the given tree.
 * @param sroot - the current root of the tree
 * @param disc - the discriminant to determine what level we are on
 * @return Node<T>* - node with the smallest value according to the disc
 */
template <typename T, typename Comp>
Node<T>* KDTree<T, Comp>::findMin(Node<T> *sroot, int disc)
{
	if (sroot->right == NULL && sroot->left == NULL)
	{
		return sroot;
	}
	Node<T>* smallLeft, *smallRight;
	if (sroot->right)
	{
		smallRight = findMin(sroot->right, disc);
		if ( Comp::lt(sroot->data, smallRight->data, disc) )
		{
			smallRight = sroot;
		}
	}
	else 
	{
		smallRight = sroot;
	}
	if (sroot->left)
	{
		smallLeft = findMin(sroot->left, disc);
		if ( Comp::lt(sroot->data, smallLeft->data, disc) )
		{
			smallLeft = sroot;
		}
	}
	else
	{
		 smallLeft = sroot;
	}
	if ( Comp::lt(smallLeft->data, smallRight->data, disc) )
	{
		return smallLeft;
	}
	return smallRight;
}
// -------------------------------------------------------------------------
/**
* This displays all important information to know about the KDTree.
* @param out - the output stream to be used for displaying.
*/
template <typename T, typename Comp>
void KDTree<T, Comp>::display(ostream& out) const
{
  	out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	out << "DATA STRUCTURE: KD Tree" << endl;
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
template <typename T, typename Comp>
void KDTree<T, Comp>::displayHelper(Node<T>* sroot, ostream &out, int depth) const
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
template <typename T, typename Comp>
T* KDTree<T, Comp>::clear()
{
  T* temp = clearHelper(root);
  root = NULL;
  return temp; 
}
// -------------------------------------------------------------------------
/**
* This is the private helper method for the clear method where the 
* actual code implementation is.
* @param sroot - the current root of the tree
*/
template <typename T, typename Comp>
T* KDTree<T, Comp>::clearHelper(Node<T>* sroot)
{
	T* temp = NULL;
  	if (sroot!= NULL)
  	{
  		temp = sroot->data;
  		temp->next = clearHelper(sroot->left);
  		T* temp2 = temp;
  		while ( temp2->next )
  		{
  			temp2 = temp2->next;
  		}
  		temp2->next = clearHelper(sroot->right);
  	}
  	if (sroot!= NULL)
  	{
  		sroot->right = sroot->left = NULL;
  		nodeStorage->add(sroot);
  		count--;
  	}
  	return temp;
}
// -------------------------------------------------------------------------
/**
 * This will return the number of nodes in the tree.
 * @return - the number of nodes in the tree.
 */
template <typename T, typename Comp>
int KDTree<T, Comp>::size() const
{
	return count;
}
#endif /*KDTREEIMPLEMENTATION_H_*/
