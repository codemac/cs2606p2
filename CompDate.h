#ifndef COMPDATE_H
#define COMPDATE_H

#include "Record.h"

class CompDate {
	public:
		bool lt(Record* lhs, Record* rhs);
		bool equal(Record* lhs, Record* rhs);
};
#endif
