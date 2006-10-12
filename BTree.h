#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "NodeADT.h"
#include "LeafNode.h"
#include "InternalNode.h"


using namespace std;

template <typename T, typename C>
class BTree {
	private:
		NodeADT* root;
		ostream out;

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

template <typename T, typename C>
void BTree<T,C>::setOut(const ostream& out) {
	this->out = out;
}

template <typename T, typename C>
void BTree<T,C>::getOut() {
	return out;
}

template <typename T, typename C>
void BTree<T,C>::BTree() {
	this->out = cout;
	root = new LeafNode();
}

template <typename T, typename C>
void BTree<T,C>::BTree(const ostream& out) {
	this->out = out;
	root = new LeafNode();
}

template <typename T, typename C>
bool BTree<T,C>::insert(T* obj) {
	root.insert(obj);
}

template <typename T, typename C>
void BTree<T,C>::search(T* obj) {
	root.search(obj,out);
}

template <typename T, typename C>
void BTree<T,C>::search(T* obj,T* objj) {
	root.search(obj,objj,out);
}

template <typename T, typename C>
bool BTree<T,C>::remove(T* obj) {
	out << "Not Implemented" << endl;
	return false;
}

template <typename T, typename C>
void BTree<T,C>::dump() {
	root.dump();
}


#endif
