#pragma once
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class Random
{
protected:
	int num;
	char sym;
public:
	virtual int random() = 0;
};
class RandomNumber :public Random
{
public:
	int random();
};
class RandomOperation :public Random
{
public:
	int random();
};
class RandomFactory
{
public:
	Random *randomrandom(string name)
	{
		if (name == "rannum")
			return new RandomNumber;
		else if (name == "ranope")
			return new RandomOperation;
	}
};