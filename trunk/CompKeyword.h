#ifndef COMPKEYWORD_H
#define COMPKEYWORD_H

#include "Record.h"

class CompKeyword {
	public:
		bool lt(Record* lhs, Record* rhs);
		bool equal(Record* lhs, Record* rhs);
};
#endif
