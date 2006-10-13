#ifndef INTERNALNODE_H
#define INTERNALNODE_H

#include <iostream>
#include "NodeADT.h"

using namespace std;

/**
 * Internal Node class
 * Used as internal nodes in a BTree following the NodeADT interface
 */
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
		InternalNode(D* lDisc, D* rDisc, NodeADT* chil1, NodeADT* chil2, NodeADT* chil3);
		~InternalNode();

		virtual InternalNode<T,D,C>* insert(T* obj);
		virtual void search(T* obj, const ostream& out);
		virtual void search(T* low, T* high, const ostream& out);
		virtual void remove(T* obj);
		virtual bool isFull();
		virtual void dump(int level, const ostream& out);
};
/**
 * default constructor
 */
template <typename T, typename D, typename C>
InternalNode<T,D,C>::InternalNode()
{
	rDiscrim = NULL;
	lDiscrim = NULL;
	one = NULL;
	two = NULL;
	three = NULL;
}

template <typename T, typename D, typename C>
InternalNode<T,D,C>::InternalNode(D* lDisc, D* rDisc, NodeADT* chil1, NodeADT* chil2, NodeADT* chil3)
{
	lDiscrim = lDisc;
	rDiscrim = rDisc;
	one = chil1;
	two = chil2;
	three = chil3;	
}

template <typename T, typename D, typename C>
bool InternalNode<T,D,C>::isLeaf() 
{
	return false;
}

template <typename T, typename D, typename C>
void InternalNode<T,D,C>::dump(int level, const ostream& out) 
{
	for ( int i = 0; i < level; i++ )
	{
		out << "-";
	}
	out << "Internal Node: " << C::dump(lDiscrim*) << ", " << C::dump(rDiscrim*) << endl;
	
	one->dump(level+1, out);
	two->dump(level+1, out);
	three->dump(level+1, out);
}

template <typename T, typename D, typename C>
void InternalNode<T,D,C>::search(T* obj, const ostream& out) 
{
	if ( C::lt(obj, *lDiscrim) )
	{
		one->search(obj, out);
	}
	else if ( three )
	{
		if ( C::lt(obj, *rDiscrim) )
		{
			two->search(obj, out);
		}
		else three->search(obj, out);
	}
	else two->search(obj, out);

/*	if ( one != 0 ) one->search(obj,out);
	if ( two != 0 ) two->search(obj,out);
	if ( three != 0 ) three->search(obj,out);*/
}

template <typename T, typename D, typename C>
void InternalNode<T,D,C>::search(T* low, T* high, const ostream& out) 
{
	if ( C::lt(low, *lDiscrim) )
	{
		one->search(low, high, out);
	}
	else if ( three )
	{
		if ( C::lt(low, *rDiscrim) )
		{
			two->search(low, high, out);
		}
		else three->search(low, high, out);
	}
	else two->search(low, high, out);
	
	/*if ( one != 0 ) one->search(obj,objj,out);
	if ( two != 0 ) two->search(obj,objj,out);
	if ( three != 0 ) three->search(obj,objj,out);*/
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
	if ( C::lt(obj, *lDiscrim) )
	{
		InternalNode<T,D,C> inter = one->insert(obj);
		if ( inter )
		{
			if ( three )
			{
				InternalNode<T,C>* temp = new InternalNode(rDiscrim, NULL, two, three, NULL);
				two = inter;
				rDiscrim = NULL;
				lDiscrim = two->lObject->getDiscrim();
				three = NULL;
				return temp;
			}
			else
			{
				three = two;
				two = inter;
				rDiscrim = lDiscrim;
				lDiscrim = two->lObject->getDiscrim();
				return NULL;	
			}
		}
		else return NULL;
	}
	else if ( C::lt(obj, *rDiscrim) )
	{
		InternalNode<T,D,C> inter = two->insert(obj);
		if ( inter )
		{
			if ( three )
			{
				InternalNode<T,C>* temp = new InternalNode(rDiscrim, NULL, inter, three, NULL);
				rDiscrim = NULL;
				lDiscrim = two->lObject->getDiscrim();
				three = NULL;
				return temp;
			}
			else
			{
				three = inter;
				rDiscrim = three->lObject->getDiscrim();
				lDiscrim = two->lObject->getDiscrim();
				return NULL;	
			}
		}
		else return NULL;
	}
	else
	{
		InternalNode<T,D,C> inter = three->insert(obj);
		if ( inter )
		{
			InternalNode<T,C>* temp = new InternalNode(inter->getDiscrim(), NULL, three, inter, NULL);
			rDiscrim = NULL;
			three = NULL;
			return temp;
		}
		else return NULL;
	}
}

template <typename T, typename D, typename C>
InternalNode<T,D,C>* InternalNode<T,D,C>::insertToLeaf(T* obj) 
{
	if ( C::lt(obj, *lDiscrim) )
	{
		LeafNode<T,C>* leaf = one->insert(obj);
		if ( leaf )
		{			
			if ( three )
			{
				InternalNode<T,C>* temp = new InternalNode(rDiscrim, NULL, two, three, NULL);
				two = leaf;
				rDiscrim = NULL;
				lDiscrim = two->lObject->getDiscrim();
				three = NULL;
				return temp;
			}
			else
			{
				three = two;
				two = leaf;
				rDiscrim = lDiscrim;
				lDiscrim = two->lObject->getDiscrim();
			}
		}
		else return NULL;
	}
	else if ( C::lt(obj, *rDiscrim) )
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
