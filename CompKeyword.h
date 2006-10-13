#ifndef COMPKEYWORD_H
#define COMPKEYWORD_H

#include "Record.h"

class CompKeyword {
	public:
		bool lt(Record* lhs, Record* rhs);
//		bool lt(Record* lhs, string rhs);
		bool equal(Record* lhs, Record* rhs);
		void dump(Record* obj);
};
#endif
