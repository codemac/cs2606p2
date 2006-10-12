#include "CompDate.h"

bool CompDate::lt(Record* lhs, Record* rhs) {
	return lhs->date() < rhs->date();
}

bool CompDate::equal(Record* lhs, Record* rhs) {
	return lhs->date() == lhs->date();
}
