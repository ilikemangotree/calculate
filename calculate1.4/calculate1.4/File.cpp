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
	fstream file;
	file.open(inputfile);
	file >> n;
	file.close();
	return n;

}
void File::outputfile(char *path, string equ, string answer, int rightanswer,char *boundadry)
{
	fstream file;
	file.open(path,ios::app);
	file << equ << answer << endl;
	file << boundadry << rightanswer << endl;
	file << "========================" << endl << endl;
	file.close();

}
void File::outputfile(char *path, char *boundadry, int n)
{
	fstream file;
	file.open(path, ios::app);
	file.clear();
	file << boundadry << n << endl;
	file << "========================" << endl << endl;
	file.close();
}
