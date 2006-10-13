#ifndef COMPID_H
#define COMPID_H

#include "Record.h"

class CompID {
	public:
		bool lt(Record* lhs, Record* rhs);
		bool lt(Record* lhs, unsigned int rhs);
		unsigned int* getDiscrim(Record* obj);
		bool equal(Record* lhs, Record* rhs);
		void dump(Record* obj);
};
#endif
