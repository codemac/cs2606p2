#include "CompKeyword.h"

/**
 * Logically a < operation on the records' keyword variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs keyword < rhs keyword
 */
bool CompKeyword::lt(Record* lhs, Record* rhs) {
	return *lhs->keyword() < *rhs->keyword();
}

/**
 * Logically a < operation on the record's keyword variable and a string
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs keyword < rhs
 */
bool CompKeyword::lt(Record* lhs, string rhs) 
{
	string* word = lhs->keyword();

	if ( rhs == *word )
	{
		delete word;
		return true;
	}
	
	delete word;
	return false;
}


/**
 * Returns the discriminate of the sent in record based on this comparator
 * @param obj the record to get the discriminate from
 * @return the keyword of the record
 */
string* CompKeyword::getDiscrim(Record* obj)
{
	return obj->keyword();	
}

/**
 * Logically a == operation on the records' keyword variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs keyword == rhs keyword
 */
bool CompKeyword::equal(Record* lhs, Record* rhs) 
{
	string* rWord = rhs->keyword();
	string* lWord = lhs->keyword();
	
	if ( *rWord == *lWord )
	{
		delete rWord;
		delete lWord;
		return true;
	}

	delete rWord;
	delete lWord;
	return false;
	
}

/**
 * Prints out the ID and keyword of the parameter
 * @param obj the record to print out
 */
void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << *obj->keyword() << endl;
}
