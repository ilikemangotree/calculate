#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
#include "Random.h"
using namespace std;
int RandomNumber::random()
{
	num = rand() % 10 + 1;
	return num;
}
int RandomOperation::random()
{
	int n = rand() % 4;
	switch (n)
	{
	case 0: sym = '+'; break;
	case 1: sym = '-'; break;
	case 2: sym = '*'; break;
	case 3: sym = '/'; break;
	}
	return sym;
}

