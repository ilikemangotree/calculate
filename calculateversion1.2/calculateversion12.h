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
		char creat_symbol();          //������ɷ��� 
		string bracket(string n);    //����������� 
		string int_str(int number);  //������ת��Ϊ�ַ��� 
		string connect(string str1,string str2,char a);  //��������������� 
		string InfixToPostfix(string infix);   //��ǰ׺���ʽת��Ϊ��׺���ʽ 
		float posfixCompute(string s);    //�����׺���ʽ 
		float expressionCalculate(string s);   //���ʽ���� 
		int record(float answer,float input,char boundary[][200]);  //������ȷ���� 
		void result(int k,int t,char boundary[][200]);  //��ʾ��� 
	protected:
};

#endif
