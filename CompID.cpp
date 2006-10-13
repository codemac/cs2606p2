#include "CompID.h"

/**
 * Logically a < operation on the records' ID variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs ID < rhs ID
 */
bool CompID::lt(Record* lhs, Record* rhs) {
	return lhs->ID() < rhs->ID();
}

/**
 * Logically a < operation on the record's ID variable and an unsigned int
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs ID < rhs
 */
bool CompID::lt(Record* lhs, unsigned int rhs) {
	return lhs->ID() < rhs;
}

/**
 * Returns the discriminate of the sent in record based on this comparator
 * @param obj the record to get the discriminate from
 * @return the ID of the record
 */
unsigned int* CompID::getDiscrim(Record* obj)
{
	return new unsigned int(obj->ID());	
}

/**
 * Logically a == operation on the records' ID variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs ID == rhs ID
 */
bool equal(Record* lhs, Record* rhs) {
	return lhs->ID() == rhs->ID();
}

/**
 * Prints out the ID of the parameter twice
 * @param obj the record to print out
 */
void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->ID() << endl;
}
