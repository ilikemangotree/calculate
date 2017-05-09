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

public:
	int randomNumber();				//用于随机生成数字;
	char randomOperation();			//用于随机生成运算符
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