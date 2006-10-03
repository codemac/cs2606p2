#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>

using namespace std;

/**
 * This class takes stdin, and gives back an array of strings in a pointer
 * so that some other interpreter class can take the tokenized results and 
 * perform some function on them
 */
class Parser
{
	private:
		istream in;

	public:
		Parser(const istream &in);
		Parser();
		~Parser();
};
#endif
