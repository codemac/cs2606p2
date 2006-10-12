#include "CompCost.h"

bool CompCost::lt(Record* lhs, Record* rhs) {
	return lhs->cost() < rhs->cost();
}

bool CompCost::equal(Record* lhs, Record* rhs) {
	return lhs->cost() == rhs->cost();
}
