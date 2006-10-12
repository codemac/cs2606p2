#ifndef COMPID_H
#define COMPID_H

#include "Record.h"

class CompID {
	public:
		bool lt(Record* lhs, Record* rhs);
		bool equal(Record* lhs, Record* rhs);
		void dump(Record* obj);
};
#endif
