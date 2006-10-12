#ifndef LEAFNODE_H
#define LEAFNODE_H

#include <iostream>
#include "NodeADT.h"
#include "InternalNode.h"

using namespace std;

template <typename T, typename C>
class LeafNode : public NodeADT {
	private:
		T* lObject;
		T* rObject;
		
		LeafNode<T,C>* sibling;
		virtual LeafNode<T,C>* split(T* obj);

	public:
		LeafNode();
		LeafNode(T* lobj, T* robj, LeafNode<T,C>* sibling);
		~LeafNode();

		virtual LeafNode<T,C>* insert(T* obj); 
		virtual void search(T* obj, const ostream& out);
		virtual void remove(T* obj);
		virtual bool isFull();
		virtual void dump();
		

		friend class InternalNode;
};

template <typename T, typename C>
LeafNode<T,C>* LeafNode<T,C>::insert(T* obj) {
	if ( lObject == 0 ) {
		lObject = obj;
		return NULL;
	}
	else if ( rObject == 0 ) {
		if ( C::lt(*lObject, *obj) ) {	//		lObject <= obj
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

template <typename T, typename C>
void LeafNode<T,C>::search(T* obj, const ostream& out) {
}

template <typename T, typename C>
void LeafNode<T,C>::dump() {
	C::dump(lObject);
	C::dump(rObject);
}

template <typename T, typename C>
bool LeafNode<T,C>::isFull()
{
	if ( lObject == 0 && rObject == 0 ) return true;
	return false;
}

template <typename T, typename C>
LeafNode<T,C>* LeafNode<T,C>::split(T* obj)
{
	if ( !isFull() ) return NULL;
	
	if ( C::lt(obj*, lObject*) )
	{
		LeafNode<T,C>* temp = new LeafNode<T,C>(lObject, rObject, NULL);
		sibling = temp;
		rObject = NULL;
		lObject = obj;
		return temp;
	}
	else if ( C::lt(rObject*, obj*) )
	{
		LeafNode<T,C>* temp = new LeafNode<T,C>(rObject, obj, NULL);
		sibling = temp;
		rObject = NULL;
		return temp;
	}
	else
	{
		LeafNode<T,C>* temp = new LeafNode<T,C>(obj, rObject, NULL);
		sibling = temp;
		rObject = NULL;
		return temp;
	}		
}

#endif
