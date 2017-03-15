#ifndef CALCULATEVERSION12_H
#define CALCULATEVERSION12_H
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class calculateversion2
{
	public:
		char creat_symbol();
		string bracket(string n);
		string int_str(int number);
		string connect(string str1,string str2,char a);
		string InfixToPostfix(string infix);
		float posfixCompute(string s);
		float expressionCalculate(string s);
		int record(float answer,float input,char boundary[][200]);
		void result(int k,int t,char boundary[][200]);
		void languagelist();
	protected:
};

#endif
