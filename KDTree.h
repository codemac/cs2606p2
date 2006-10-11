/**
 * This is a KD Tree that is implemtented in the following way:
 * When a node is inserted or removed, we use a NodeStorage object
 *  to get/save nodes. There is also a key value for each level of the tree.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef KDTREE_H_
#define KDTREE_H_
#include "Node.h"
#include "NodeStorage.h"
#include <iostream>
using namespace std;

template <typename T, typename Comp>
class KDTree
{
	private:
		
		//These are the private variables.
		NodeStorage<T>* nodeStorage; //nodestorage variable
		Node<T>* root; //points to the root of the tree
		int count; //keeps track of the number of data items in the tree
		int numKeys; //keeps track of how many keys the tree is using
		bool selfStorage; //true if the KDTree creates its own NodeStorage object
		
		//These are the private methods. 
		/**
 		* Initiates and sets up all nodes and counts.
 		*/
		void init(int num);
		/**
 		* This is the private helper method for the add method where the actual
 		* code implementation is.
 		* @param item - the item we want to store in our tree
 		* @param sroot - the current root of the tree
 		* @param level - the level of the tree we are currently on, with the root
 		* level being defined as 0
 		* @return Node<T>* - returns a pointer to our tree with the item stored
 		*/
		Node<T>* addHelper(Node<T>* sroot, T* item, int level);
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
		Node<T>* removeHelper(Node<T>* sroot, T* removeMe, T* &data, int level);
		/**
 		* This is a private helper method to help the removeHelper method.
 		* It serves to delete the specified node.
 		* @param sroot - the root of the current tree
 		* @return Node<T>* - returns a reference to the current tree
 		*/
		Node<T>* deleteNode(Node<T> *sroot, int level);
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
 		* @return T* - A pointer to the first templated object so that they can be deleted
 		*/
		T* clearHelper(Node<T>* sroot);
		/**
		 * This finds the smallest root in the given tree.
		 * @param sroot - the current root of the tree
		 * @param disc - the discriminant to determine what level we are on
		 * @return Node<T>* - node with the smallest value according to the disc
		 */
		Node<T>* findMin(Node<T> *sroot, int disc);
		/**
		 * Swaps the data holders of two nodes.
		 * @param one - the node to swap with two
		 * @param two - the node to swap with one
		 */
		void swap(Node<T> *one, Node<T>* two);
		/**
		 * Finds the level of the given node.
		 * @param sroot - the current root of the tree
		 * @param findMe - the node to find the level of
		 * @param level - the level we are currently on
		 * @return int - the level of findMe
		 */
		int findLevel(Node<T>* sroot, Node<T>* findMe, int level);
		/**
		 * This method finds the parent of the given node. If the given node
		 * is the root of the tree, it returns NULL.
		 * @param sroot - the current root of the tree
		 * @param child - the node to find the parent of
		 * @return Node<T>* - the parent of child
		 */
		Node<T>* findParent(Node<T>* sroot, Node<T>* child);
		/**
		 * This is the helper method for the find method.
		 * @param sroot - the current root of the tree
		 * @param data - the object to find
		 * @param level - the current level
		 * @return bool - returns true if the object is found, otherwise
		 * returns false.
		 */
		bool findHelper(Node<T>* sroot, T* data, int level);
		/**
		 * This is the helper method for the search method.
		 * @param sroot - the current root of the tree
		 * @param x - the x coordinate
		 * @param y - the y coordinate
		 * @param radius - the radius to use in our search
		 * @param level - the current level
		 * @return int - returns the number of nodes visited.
		 */
		int searchHelper(Node<T>* sroot, long x, long y, long radius, int level);
		/**
		 * Keeps nodes within the system of these classes
		 */
		friend class NodeStorage<T>;
		friend class Node<T>;
		
	public:
		
		//These are the public methods.
		/**
 		* Default constructor.  This creates the KDTree given the number of keys
 		* and initializes the NodeStorage.
 		*/
		KDTree(int num);
		/**
		 * This constructor creates the KDTree given the number of keys and a 
		 * NodeStorage object.
		 */
        KDTree(int num, NodeStorage<T>* ns);
		/**
 		* The destructor for the KDTree. This will make sure we clean up our pointers.
 		*/
		virtual ~KDTree();
		/**
 		* This method will allow us to add items to our tree.  If an item is less than
 		* it's parent,based on the descriminant at that level, it is put to the left, 
 		* otherwise it goes to the right.
 		* @param item - the item we want to store in our tree.
 		*/
 		virtual void add(T* item);
 		/**
 		 * This is the search method that finds all of the nodes within the circle
 		 * created by the given center and radius.
 		 * @param x - the x coordinate of the center of the circle
		 * @param y - the y coordinate of the center of the circle
		 * @param radius - the radius of the circle
		 */
 		virtual void search(long x, long y, long radius);
		/**
		* This method will remove items from our tree.  Any item can be removed from
 		* the tree, and the tree will be readjusted to fit the particular situation.
 		* The remove method has a helper method which also has it's own helper method.
 		* @param removeMe - the item we want to remove from our tree.  Used over (int,int)
 		* so that the KD Tree stays generic in how many keys it has.
 		* @return T* - the data object removed
 		*/
		virtual T* removeByCoords(T* removeMe);
		/**
		 * This is the find method that finds the given object in the tree, if it is there.
		 * @param data - the object to find
		 * @return bool - returns true if the object is found, otherwise returns false.
		 */
		virtual bool find(T* data);
		/**
		* This displays all important information to know about the KDTree.
 		* @param out - the output stream to be used for displaying.
 		*/
		virtual void display(ostream &out) const;
		/**
 		* This will return the tree to post-construction state. All data will be 
 		* removed from the tree.
		* @return T* - A pointer to the first templated object so that they can be deleted
 		*/
		virtual T* clear();
		/**
 		* This will return the number of nodes in the tree.
 		* @return int - the number of nodes in the tree.
 		*/
		virtual int size() const;
};
#include "KDTreeImplementation.h"
	
#endif /*KDTREE_H_*/
