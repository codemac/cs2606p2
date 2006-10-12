#ifndef SYSTEM_H
#define SYSTEM_H

#include "KDTree.h"
#include "BTree.h"
#include "Parser.h"

using namespace std;

class System {
	private:
		Parser p;
		KDTree coord;
		BTree cost, date, keyword, id;
	public:
		void run();
};
#endif
