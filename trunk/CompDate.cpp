#include "CompDate.h"

bool CompDate::lt(Record* lhs, Record* rhs) {
	return lhs->date() < rhs->date();
}

bool CompDate::lt(Record* lhs, string rhs) {
	return lhs->date() < rhs;
}

string* CompDate::getDiscrim(Record* obj)
{
	return new string(lhs->date);
}

bool CompDate::equal(Record* lhs, Record* rhs) {
	return lhs->date() == lhs->date();
}

void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->date() << endl;
}
