#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "list.h"
#include<list>
#include <iostream>
using namespace std;

int main()
{ 
	List<int> x; 
	ListItem<int>* it=NULL;
	ListItem<int>* it2 = NULL;
	x.push_back(1);
	it2=x.push_back(2); 
	it=x.push_back(3);
	x.push_back(4);
	x.push_back(5);
	x.remove(x.first(), it);


	
	
	_CrtDumpMemoryLeaks();

	
	return 0;
}