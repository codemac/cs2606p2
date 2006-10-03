#ifndef RECORD_H
#define RECORD_H

#include <string>

using namespace std;

class Record {
	private:
		string ttitle,				///	record title
			   ddatetime,			///	date in format YYMMDDHHmm
			   ddescription;			/// record description

		unsigned int llength,		///	length in minutes
					 ccost,			///	cost in whole dollar amounts
					 IID;			///	unique ID

		unsigned short int xx,		///	coordinate for the X axis
					       yy;		///	coordinate for the Y axis
		

		class Keyword
		{
			Keyword* next;
			Keyword* prev;
			string data;

			Keyword(prev,next,data)
			{
				this->next = next;
				this->prev = prev;
				this->data = data;
			}
			Keyword()
			{
				next = 0;
				prev = 0;
				data = "";
			}
		};
		
		Keyword* root;				///	Root node of keywords.

	public:

		Record();

		~Record();

		string title();
		void title(const string& t);

		string date();
		void date(const string& d);

		string description();
		void description(const string& d);

		unsigned int length();
		void length(const unsigned int& l);

		unsigned int cost();
		void cost(const unsigned int& c);

		unsigned int ID();
		void ID(const unsigned int& i);

		unsigned short int x();
		void x(const unsigned short int& x);

		unsigned short int y();
		void y(const unsigned short int& y);

		unsigned short int* coords();
};
#endif
