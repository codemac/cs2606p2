#include "CompID.h"

bool CompID::lt(Record* lhs, Record* rhs) {
	return lhs->ID() < rhs->ID();
}

bool equal(Record* lhs, Record* rhs) {
	return lhs->ID() == rhs->ID();
}
