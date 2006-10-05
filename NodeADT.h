#ifndef NODEADT_H
#define NODEADT_H

template <typename T>
class NodeADT {
	public:
		virtual void insert(T* obj) = 0;
		virtual void search(T* obj) = 0;
		virtual void remove(T* obj) = 0;
};
#endif
