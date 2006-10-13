#include "CompCost.h"

bool CompCost::lt(Record* lhs, Record* rhs) {
	return lhs->cost() < rhs->cost();
}

bool CompCost::lt(Record* lhs, unsigned int rhs) {
	return lhs->cost() < rhs;
}

bool CompCost::equal(Record* lhs, Record* rhs) {
	return lhs->cost() == rhs->cost();
}

void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->cost() << endl;
}