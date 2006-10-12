#include "CompID.h"

bool CompID::lt(Record* lhs, Record* rhs) {
	return lhs->ID() < rhs->ID();
}

bool equal(Record* lhs, Record* rhs) {
	return lhs->ID() == rhs->ID();
}

void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->ID() << endl;
}
