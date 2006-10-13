#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "NodeADT.h"
#include "LeafNode.h"
#include "InternalNode.h"


using namespace std;

/***
 * This class is made to simulate a 2-3+ btree.
 */

template <typename T, typename C>
class BTree {
	private:
		NodeADT* root;		//	Root node of the tree
		ostream out;		//	out stream to print to

	public:
		BTree();
		BTree(const ostream& out);
		~BTree();
		
		void setOut(const ostream& out);
		ostream getOut();
		bool insert(T* obj);
		void search(T* obj);
		void search(T* obj, T* objj);
		bool remove(T* obj);
		void dump();
};

/**
 * set out to the correct ostream
 * @param out Ostream to print to.
 */
template <typename T, typename C>
void BTree<T,C>::setOut(const ostream& out) {
	this->out = out;
}

/**
 * Returns outstream
 * @return outstream
 */
template <typename T, typename C>
ostream BTree<T,C>::getOut() {
	return out;
}

/**
 * Standard constructor
 */
template <typename T, typename C>
BTree<T,C>::BTree() {
	this->out = cout;
	root = new LeafNode();
}

/**
 * constructor that takes the ostream as a parameter
 * @param out Out stream to print to
 */
template <typename T, typename C>
BTree<T,C>::BTree(const ostream& out) {
	this->out = out;
	root = new LeafNode();
}

/**
 * insert object into btree
 * @param obj Object to insert
 * @return bool Success of insert
 */
template <typename T, typename C>
bool BTree<T,C>::insert(T* obj) 
{
	NodeADT* sib = root->insert(obj);
	if ( temp )
	{
		if ( root->isLeaf() )
		{
			NodeADT* temp = new InternalNode(C::getDiscrim(sib->lObject), NULL, root, sib, NULL);
		}
		else NodeADT* temp = new InternalNode(sib->lDiscrim, NULL, root, sib, NULL);
		root = temp;
	}
}

/**
 * Search tree for obj
 * @param obj Object to search for
 */
template <typename T, typename C>
void BTree<T,C>::search(T* obj) {
	root->search(obj,out);
}

/**
 * Search tree with 2 parameters for a range
 * @param obj Low end of range
 * @param objj High end of range
 */
template <typename T, typename C>
void BTree<T,C>::search(T* obj,T* objj) {
	root->search(obj,objj,out);
}

/**
 * Remove an object from the Btree
 * @param obj Object to remove
 * @return bool Success of removal
 */
template <typename T, typename C>
bool BTree<T,C>::remove(T* obj) {
	out << "Not Implemented" << endl;
	return false;
}

/**
 * Dump tree contents to output
 */
template <typename T, typename C>
void BTree<T,C>::dump() {
	root->dump();
}
#endif
