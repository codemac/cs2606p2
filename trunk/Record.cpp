#include "Record.h"

		string ttitle,				///	record title
			   ddatetime,			///	date in format YYMMDDHHmm
			   ddescription;			/// record description

		unsigned int llength,		///	length in minutes
					 ccost,			///	cost in whole dollar amounts
					 IID;			///	unique ID

		unsigned short int xx,		///	coordinate for the X axis
					       yy;		///	coordinate for the Y axis

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
	int* a = new int[2];

	a[0] = xx;
	a[1] = yy;

	return a;
}
