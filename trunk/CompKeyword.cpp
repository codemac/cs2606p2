#include "CompKeyword.h"

bool CompKeyword::lt(Record* lhs, Record* rhs) {
	return lhs->keyword() < rhs->keyword();
}

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

void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->keyword() << endl;
}
