#include "CompID.h"

bool CompID::lt(Record* lhs, Record* rhs) {
	return lhs->ID() < rhs->ID();
}

bool CompID::lt(Record* lhs, unsigned int rhs) {
	return lhs->ID() < rhs;
}

unsigned int* CompID::getDiscrim(Record* obj)
{
	return new unsigned int(obj->ID());	
}

bool equal(Record* lhs, Record* rhs) {
	return lhs->ID() == rhs->ID();
}

void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->ID() << endl;
}
