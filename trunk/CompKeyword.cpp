#include "CompKeyword.h"

bool CompKeyword::lt(Record* lhs, Record* rhs) {
	return lhs->keyword() < rhs->keyword();
}

bool CompKeyword::lt(Record* lhs, string rhs) 
{
	string* words = lhs->keywords();
	int numWords = lhs->numKeywords();
	
	for ( int i = 0; i < numWords; i++ )
	{
		if ( rhs == words[i] )
		{
			delete[] words;
			return true;
		}
	}
}

bool CompKeyword::equal(Record* lhs, Record* rhs) 
{
	int numLhs = lhs->numKeywords();
	int numRhs = lhs->numKeywords();
	
	if ( numRhs != numLhs ) return false;
	
	string* lWords = lhs->keywords();
	string* rWords = rhs->keywords();
	
	for ( int i = 0; i < numLhs; i++ )
	{
		
	
	return lhs->keyword() == rhs->keyword();
}

void CompCost::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->keyword() << endl;
}
