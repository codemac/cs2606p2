#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <sstream>
#include "Record.h"
#include "KDTree.h"
#include "BTree.h"
#include "Parser.h"
#include "CompDate.h"
#include "CompKeyword.h"
#include "CompCost.h"
#include "CompID.h"


using namespace std;

class System {
	private:
		Parser p;
		KDTree coord;
		BTree<Record, CompCost> cost;
		BTree<Record, CompDate> date;
		BTree<Record, CompKeyword> keyword;
		BTree<Record, CompID> id;
	public:
		System();
		~System();
		void run(const ostream& out);
};
#endif
