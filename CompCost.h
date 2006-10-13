#ifndef COMPCOST_H
#define COMPCOST_H

#include "Record.h"

class CompCost {
	public:
		bool lt(Record* lhs, Record* rhs);
		bool lt(Record* lhs, unsigned int rhs);
		bool equal(Record* lhs, Record* rhs);
		void dump(Record* obj);
};
#endif
