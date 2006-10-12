#include "CompKeyword.h"

bool CompKeyword::lt(Record* lhs, Record* rhs) {
	return lhs->keyword() < rhs->keyword();
}

bool CompKeyword::equal(Record* lhs, Record* rhs) {
	return lhs->keyword() == rhs->keyword();
}

void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->keyword() << endl;
}
