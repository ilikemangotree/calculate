#include "File.h"	
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
#include<string>
using namespace std;
int File::inputcount(char *inputfile)
{
	int n;
	fstream file;
	file.open(inputfile);
	file >> n;
	file.close();
	return n;

}
void File::outputfile(char *outputfile,char *p=NULL,int n=-1000)
{
	fstream file;
	file.open(outputfile);
	if (n == -1000)
	{
		file << p << endl;
	}
	else
	{
		file << p << n <<endl;
		file << "========================" << endl;
	}

	file.close();
}
void File::outputfile(char *outputfile, string s, int n)
{
	fstream file;
	file.open(outputfile);
	if (n == -1000)
	{
		file << s << endl;
	}
	else
	{
		file << s << n << endl;
		file << "========================" << endl;
	}

	file.close();
}