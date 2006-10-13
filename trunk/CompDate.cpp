#include "CompDate.h"

/**
 * Logically a < operation on the records' date variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs date < rhs date
 */
bool CompDate::lt(Record* lhs, Record* rhs) {
	return lhs->date() < rhs->date();
}

/**
 * Logically a < operation on the record's date variable and a string
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs date < rhs
 */
bool CompDate::lt(Record* lhs, string rhs) {
	return lhs->date() < rhs;
}

/**
 * Returns the discriminate of the sent in record based on this comparator
 * @param obj the record to get the discriminate from
 * @return the date of the record
 */
string* CompDate::getDiscrim(Record* obj)
{
	return new string(obj->date);
}

/**
 * Logically a == operation on the records' date variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs date == rhs date
 */
bool CompDate::equal(Record* lhs, Record* rhs) {
	return lhs->date() == lhs->date();
}

/**
 * Prints out the ID and date of the parameter
 * @param obj the record to print out
 */
void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->date() << endl;
}
