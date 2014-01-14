//============================================================================
// Name        : fusion.cpp
// Author      : Herbert Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "geom/rastered_volume.h"
#include "geom/rastered_volume_2.h"

using namespace std;

int main() {

	geom::NodeManager mgr;

	cout << "Creating an empty Node:\n";

	auto e = mgr.createEmpty();
	cout << "Result is " << ((e->isEmpty())?"empty":"not empty") << "\n";

	geom::Grid g;
	auto e2 = mgr.create(g);

	cout << "Result is " << ((e2->isEmpty())?"empty":"not empty") << "\n";

	auto f = mgr.createFull();
	cout << "Result is " << ((f->isEmpty())?"empty":"not empty") << "\n";
	cout << "Result is " << ((f->isFull())?"full":"not full") << "\n";

	cout << "Result is " << ((e2->isEmpty())?"empty":"not empty") << "\n";

	return 0;
}
