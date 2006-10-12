#include "CompKeyword.h"

bool CompKeyword::lt(Record* lhs, Record* rhs) {
	return lhs->Keyword() < rhs->Keyword();
}

bool CompKeyword::equal(Record* lhs, Record* rhs) {
	return lhs->Keyword() == rhs->Keyword();
}
