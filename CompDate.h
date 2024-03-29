#ifndef COMPDATE_H
#define COMPDATE_H

#include "Record.h"

class CompDate {
	public:
		bool lt(Record* lhs, Record* rhs);
		bool equal(Record* lhs, Record* rhs);
		string* getDiscrim(Record* obj);
		bool equal(Record* lhs, string rhs);
		void CompCost::dump(Record* obj);
};
#endif
