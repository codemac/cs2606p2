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

		virtual InternalNode<T,D,C>* insertToLeaf(T* obj);
		virtual InternalNode<T,D,C>* insertToInternal(T* obj);
	public:
		InternalNode();
		InternalNode(D* disc1, D* disc2, NodeADT* chil1, NodeADT* chil2, NodeADT* chil3);
		~InternalNode();

		virtual InternalNode<T,D,C>* insert(T* obj);
		virtual void search(T* obj, const ostream& out);
		virtual void search(T* obj, T* objj, const ostream& out);
		virtual void remove(T* obj);
		virtual bool isFull();
		virtual void dump();
};

template <typename T, typename D, typename C>
bool InternalNode<T,D,C>::isLeaf() 
{
	return false;
}

template <typename T, typename D, typename C>
void InternalNode<T,D,C>::dump() {
	
}

template <typename T, typename D, typename C>
void InternalNode<T,D,C>::search(T* obj, const ostream& out) {
	if ( one != 0 ) one->search(obj,out);
	if ( two != 0 ) two->search(obj,out);
	if ( three != 0 ) three->search(obj,out);
}

template <typename T, typename D, typename C>
void InternalNode<T,D,C>::search(T* obj, T* objj, const ostream& out) {
	if ( one != 0 ) one->search(obj,objj,out);
	if ( two != 0 ) two->search(obj,objj,out);
	if ( three != 0 ) three->search(obj,objj,out);
}

template <typename T, typename D, typename C>
InternalNode<T,D,C>* InternalNode<T,D,C>::insert(T* obj) 
{
	if ( chil1->isLeaf() ) return insertToLeaf(obj);
	
	return insertToInternal(obj);
}

template <typename T, typename D, typename C>
InternalNode<T,D,C>* InternalNode<T,D,C>::insertToInternal(T* obj) 
{
	
}

template <typename T, typename D, typename C>
InternalNode<T,D,C>* InternalNode<T,D,C>::insertToLeaf(T* obj) 
{
	if ( C::lt(*obj, *lDiscrim) )
	{
		LeafNode<T,C>* leaf = one->insert(obj);
		if ( leaf )
		{			
			if ( three )
			{
				InternalNode<T,C>* temp = new InternalNode(rDiscrim, NULL, two, three, NULL);
				two = leaf;
				three = NULL;
				return temp;
			}
			else
			{
				three = two;
				two = leaf;
				lDiscrim = two->lObject->getDiscrim();
				rDiscrim = three->lObject->getDiscrim();
			}
		}
		else return NULL;
	}
	else if ( C::lt(*obj, *rDiscrim) )
	{
		LeafNode<T,C>* leaf = two->insert(obj);
		if ( leaf )
		{
			if ( three )
			{
				InternalNode<T,C>* temp = new InternalNode(rDiscrim, NULL, leaf, three, NULL);
				three = NULL;
				return temp;
			}
			else
			{
				three = leaf;
				rDiscrim = three->lObject->getDiscrim();
			}
		}
		else return NULL;
	}
	else
	{
		LeafNode<T,C>* leaf = three->insert(obj);
		if ( leaf )
		{
			InternalNode<T,C>* temp = new InternalNode(rDiscrim, NULL, three, leaf, NULL);
			three = NULL;
			return temp;
		}
		else return NULL;
	}
}

#endif