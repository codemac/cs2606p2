#include "CompCost.h"

/**
 * Logically a < operation on the records' cost variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs cost < rhs cost
 */
bool CompCost::lt(Record* lhs, Record* rhs) {
	return lhs->cost() < rhs->cost();
}

/**
 * Logically a < operation on the record's cost variable and an unsigned int
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs cost < rhs
 */
bool CompCost::lt(Record* lhs, unsigned int rhs) {
	return lhs->cost() < rhs;
}

/**
 * Returns the discriminate of the sent in record based on this comparator
 * @param obj the record to get the discriminate from
 * @return the cost of the record
 */
unsigned int* CompCost::getDiscrim(Record* obj)
{
	return new unsigned int(obj->cost());
}

/**
 * Logically a == operation on the records' cost variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs cost == rhs cost
 */
bool CompCost::equal(Record* lhs, Record* rhs) {
	return lhs->cost() == rhs->cost();
}

/**
 * Prints out the ID and cost of the parameter
 * @param obj the record to print out
 */
void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->cost() << endl;
}
