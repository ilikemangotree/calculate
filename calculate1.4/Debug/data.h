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
	int randomNumber();				//���������������;
	char randomOperation();			//����������������
	string bracket(string n);    //����������� 
	string int_str(int number); //������ת��Ϊ�ַ��� 
	string connect(string str1, string str2, char a);  //��������������� 
	string InfixToPostfix(string infix);   //��ǰ׺���ʽת��Ϊ��׺���ʽ 
	int expressionCalculate(string s);  //������ȷ��
	int posfixCompute(string s);    //�����׺���ʽ  
	int record(int answer, int input);  //������ȷ���� 

	 

protected:
};
#endif