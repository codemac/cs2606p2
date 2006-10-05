#ifndef INTERNALNODE_H
#define INTERNALNODE_H

#include <iostream>
#include "NodeADT.h"

using namespace std;

template <typename T, typename D, typename C>
class InternalNode : public NodeADT {
	private:
		D* rDiscrim;
		D* lDiscrim;

		NodeADT *one, *two, *three;

	public:
		InternalNode();
		InternalNode(D* d, NodeADT* chil1, NodeADT* chil2);
		~InternalNode();

		virtual bool insert(T* obj);
		virtual void search(T* obj, const ostream& out);
		virtual void remove(T* obj);
		virtual void dump();
};


template <typename T, typename D, typename C>
void InternalNode<T,D,C>::dump() {
	
}

#endif
