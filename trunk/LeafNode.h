#ifndef LEAFNODE_H
#define LEAFNODE_H

#include <iostream>
#include "NodeADT.h"
#include "InternalNode.h"

using namespace std;

template <typename T, typename C>
class LeafNode : public NodeADT {
	private:
		T* rObject;
		T* lObject;
		
		LeafNode<T,C>* sibling;

	public:
		LeafNode();
		LeafNode(T* robj, T* lobj, LeafNode<T,C>* sibling);
		~LeafNode();

		virtual bool insert(T* obj); 
		virtual void search(T* obj, const ostream& out);
		virtual void remove(T* obj);
		virtual void dump();

		friend class InternalNode;
};

template <typename T, typename C>
bool LeafNode<T,C>::insert(T* obj) {
	if ( lObject == 0 ) {
		lObject = obj;
		return true;
	}
	else if ( rObject == 0 ) {
		if ( C::lte(*lObject, *obj) ) {	//		lObject <= obj
			rObject = obj;
		}
		else {
			rObject = lObject;
			lObject = obj;
		}
		return true;
	}
	else {
		return false;
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
#endif
