#include "Record.h"
/**
 * This is all getters and setters, it's self explanitory
 */
Record::Record() {
}
Record::~Record() {
}

string Record::title() {
	return ttitle;
}

void Record::title(const string& t) {
	ttitle = t;
}

string Record::date() {
	return ddatetime;
}

void Record::date(const string& d) {
	ddatetime = d;
}

string Record::description() {
	return ddescription;
}

void Record::description(const string& d) {
	ddescription = d;
}

unsigned int Record::length() {
	return llength;
}

void Record::length(const unsigned int& l) {
	llength = l;
}

unsigned int Record::cost() {
	return ccost;
}

void Record::cost(const unsigned int& c) {
	ccost = c;
}

unsigned int Record::ID() {
	return IID;
}

void Record::ID(const unsigned int& i) {
	IID = i;
}

unsigned short int Record::x() {
	return xx;
}

void Record::x(const unsigned short int& x) {
	xx = x;
}

unsigned short int Record::y() {
	return yy;
}

void Record::y(const unsigned short int& y) {
	yy = y;
}

unsigned short int* Record::coords() {
	unsigned short int* a = new unsigned short int[2];

	a[0] = xx;
	a[1] = yy;

	return a;
}

string* Record::keyword(void) {
	/*int count = 0;
	Keyword* n = root;

	while ( n != 0 ) {
		n = n->next;
		count++;
	}
	
	n = root;

	string* keys = new string[count];
	
	for ( int i = 0; i < count; i++) {
		keys[i] = n->data;
		n = n->next;
	}*/

	return new string(keyword);
}

void Record::keyword(string key) {
	keywordd = key;
	/*
	if ( root == 0 )
		root = new Keyword(key, 0);
	else {
		///	find last node
		Keyword* n = root;
		while ( n->next != 0 )
			n = n->next;

		n->next = new Keyword(key, 0);
	}*/
}

/*int Record::numKeywords()
{
	int count = 0;
	Keyword* n = root;

	while ( n != 0 ) 
	{
		n = n->next;
		count++;
	}
	
	return count;
}*/




