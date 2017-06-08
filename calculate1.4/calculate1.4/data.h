#pragma once
#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class Data
{
private:
	int random;			//代表随机数,可用于生成算式中的数字，也用于随机字符和随机括号
	char randomsym;		//代表随机字符
	string equ;			//生成的算式
	string postfix;		//后缀表达式
	stack<char> mark;	//符号栈
	map<char, int> priority;		//符号优先级
	stack<int> tempResult;			//计算后缀表达式的栈
	int rightcount=0;      //记录回答正确的个数题数

public:
	string bracket(string n);    //随机生成括号 
	string int_str(int number); //将数字转换为字符串 
	string connect(string str1, string str2, char a);  //将数字与符号连接 
	string InfixToPostfix(string infix);   //将前缀表达式转换为后缀表达式 
	int expressionCalculate(string s);  //计算正确答案
	int posfixCompute(string s);    //计算后缀表达式  
	int record(int answer, int input);  //计算正确题数 

	 

protected:
};
#endif