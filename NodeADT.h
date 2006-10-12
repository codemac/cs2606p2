#ifndef NODEADT_H
#define NODEADT_H

#include <iostream>

using namespace std;

template <typename T>
class NodeADT {
	public:
		virtual bool insert(T* obj) = 0;
		virtual void search(T* obj, const ostream& out) = 0;
		virtual void remove(T* obj) = 0;
		virtual bool isLeaf();
		virtual void dump(int level, const ostream& out) = 0;
};
#endif
