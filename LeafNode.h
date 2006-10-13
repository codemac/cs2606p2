#ifndef LEAFNODE_H
#define LEAFNODE_H

#include <iostream>
#include "NodeADT.h"
#include "InternalNode.h"

using namespace std;

/**
 * Leaf node class for use in a 2-3+ BTree.  Templated on both the object
 * for it to hold, and the comparator to compare the object by.
 */
template <typename T, typename C>
class LeafNode : public NodeADT {
	private:
		T* lObject;
		T* rObject;
		
		LeafNode<T,C>* sibling;
		virtual LeafNode<T,C>* split(T* obj);

	public:
		LeafNode();
		LeafNode(T* lobj, T* robj, LeafNode<T,C>* sib);
		~LeafNode();

		virtual LeafNode<T,C>* insert(T* obj); 
		virtual void search(T* obj, const ostream& out);
		virtual void search(T* obj, T* objj, const ostream& out);
		virtual void remove(T* obj);
		virtual bool isFull();
		virtual bool isFull();
		virtual void dump();
		

		friend class InternalNode;
};

/**
 * Standard constructor
 */
template <typename T, typename C>
LeafNode<T,C>::LeafNode<T,C>()
{
	lObject = NULL;
	rObject = NULL;
	sibling = NULL;
}

/**
 * Constructor that takes parameters to set up object
 * @param lobj Left object
 * @param robj Right object
 * @param sib Sibling to link to
 */
template <typename T, typename C>
LeafNode<T,C>::LeafNode<T,C>(T* lobj, T* robj, LeafNode<T,C>* sib)
{
	lObject = lobj;
	rObject = robj;
	sibling = sib;
}

/**
 * Insert a node into the leaf level
 * @param obj Object to insert
 * @return results of split or null
 */
template <typename T, typename C>
LeafNode<T,C>* LeafNode<T,C>::insert(T* obj) {
	if ( lObject == 0 ) {
		lObject = obj;
		return NULL;
	}
	else if ( rObject == 0 ) {
		if ( C::lt(*lObject, *obj) ) {	//		lObject < obj
			rObject = obj;
		}
		else {
			rObject = lObject;
			lObject = obj;
		}
		return NULL;
	}
	else {
		return split(obj);
	}
}

/**
 * Search for object in tree
 * @param obj object to search for
 * @param out Out stream to print to
 */
template <typename T, typename C>
void LeafNode<T,C>::search(T* obj, const ostream& out) {
	if ( C::equal(lObject,obj)) {
		out << C::dump(lObject) << endl;
	}
	if ( C::equal(rObject,obj)) {
		out << C::dump(rObject) << endl;
		if (sibling != 0) {
			sibling->search(obj,out);
		}
	}
	if ( C::lt(rObject,obj) ) {
		if (sibling != 0) {
			sibling->search(obj,out);
		}
	}
}

/**
 * Search for a range of nodes
 * @param obj Low end range
 * @param objj High end range
 * @param out Out stream to print to
 */
template <typename T, typename C>
void LeafNode<T,C>::search(T* obj, T* objj, const ostream& out) {
	if ( C::lt(rObject,obj) )				///		If biggest object is too small, move to sibling
		if (sibling != 0) {
			sibling->search(obj,objj,out);
		}
		return;
	else if ( C::lt(objj,lObject) )			///		if smallest object is too big, stop calling search
		return;
	
	if ( C::lt(obj, lObject) )
		out << C::dump(lObject);
	
	if ( C::lt(rObject, objj) || C::equal(rObject, objj) )
		out << C::dump(rObject);
	else
		return;

	if (sibling != 0)
		sibling->search(obj,objj,out);
}


/**
 * dump contents of node to out stream
 */
template <typename T, typename C>
void LeafNode<T,C>::dump() {
	C::dump(lObject);
	C::dump(rObject);
}

/**
 * Return if this node is a leaf or not
 * @return bool True because this is a LeafNode
 */
template <typename T, typename C>
bool LeafNode<T,C>::isLeaf()
{
	return true;	
}

/**
 * Is tree full?
 * @return bool True if tree is full, false if tree is not full
 */
template <typename T, typename C>
bool LeafNode<T,C>::isFull()
{
	if ( lObject == 0 && rObject == 0 ) return true;
	return false;
}

/**
 * Split the node and create new nodes
 * @param obj Object to split on
 * @return LeafNode<T,C>* Results of split
 */
template <typename T, typename C>
LeafNode<T,C>* LeafNode<T,C>::split(T* obj)
{
	if ( !isFull() ) return NULL;
	
	if ( C::lt(obj*, lObject*) )
	{
		LeafNode<T,C>* temp = new LeafNode<T,C>(lObject, rObject, sibling);
		sibling = temp;
		rObject = NULL;
		lObject = obj;
		return temp;
	}
	else if ( C::lt(rObject*, obj*) )
	{
		LeafNode<T,C>* temp = new LeafNode<T,C>(rObject, obj, sibling);
		temp->sibling = sibling;
		sibling = temp;
		rObject = NULL;
		return temp;
	}
	else
	{
		LeafNode<T,C>* temp = new LeafNode<T,C>(obj, rObject, sibling);
		temp->sibling = sibling;
		sibling = temp;
		rObject = NULL;
		return temp;
	}		
}

#endif
