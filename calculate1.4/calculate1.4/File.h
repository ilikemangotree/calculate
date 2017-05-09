#pragma once
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class File
{
private:

public:
	int inputcount(char *inputfile);
	void outputfile(char *outputfile,char*p,int n);
	void outputfile(char *outputfile, string s, int n);



protected:
};
#endif