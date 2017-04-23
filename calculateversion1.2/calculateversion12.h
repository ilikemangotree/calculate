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
		char creat_symbol();          //随机生成符号 
		string bracket(string n);    //随机生成括号 
		string int_str(int number);  //将数字转换为字符串 
		string connect(string str1,string str2,char a);  //将数字与符号连接 
		string InfixToPostfix(string infix);   //将前缀表达式转换为后缀表达式 
		float posfixCompute(string s);    //计算后缀表达式 
		float expressionCalculate(string s);   //表达式计算 
		int record(float answer,float input,char boundary[][200]);  //计算正确题数 
		void result(int k,int t,char boundary[][200]);  //显示结果 
	protected:
};

#endif
