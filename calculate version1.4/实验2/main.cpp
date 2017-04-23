#include<iostream>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
#include "data.h"
#include "language.h"
using namespace std;
char boundadry[20][200];
int n;
void scan()		//�ú����������û���������ȡ��������
{
	language lan;
	lan.languagelist(boundadry);
	lan.languagechoice(boundadry);
}
string generateExpression(int i)		//������������ʽ
{
	int n1, n2;
	Data dat;
	n1 = dat.randomNumber();	//�������
	n2 = dat.randomNumber();	//�������
	char sign;
	sign = dat.randomOperation();	//��������ַ� 
	string str_n1, str_n2, temp;
	str_n1 = dat.int_str(n1);	//������ת��Ϊ�ַ��� 
	str_n2 = dat.int_str(n2);	//������ת��Ϊ�ַ��� 
	string equation;
	equation = dat.connect(str_n1, str_n2, sign);	//����2�����ֺ�1������ 
	for (int j = 0; j < 2; j++)
	{
		str_n1 = dat.bracket(equation);   // ÿ2�����ֺ�һ�����ž���������˼�һ������ 
		n2 = rand() % (10-1+1)+1;
		str_n2 = dat.int_str(n2);
		int exchange;
		exchange = rand() % 2;     // ���ַ���λ�ý����������
		if (exchange == 1)
		{
			temp = str_n1;
			str_n1 = str_n2;
			str_n2 = temp;
		}
		sign = dat.randomOperation();
		equation = dat.connect(str_n1, str_n2, sign);  //����2�����ֺ�1�����ſ����ɵĵ��ַ������������ɵ��������ַ������Ͼɵĵ��ַ�����
	}
	cout << "(" << i << "):" << equation << '=';      //��������ʽ 
	return equation;
}
int calculateResult(string n)	//���ڼ������ɵ�����ʽ�Ľ��()
{
	Data dat;
	return dat.expressionCalculate(n);
}
int print(int n,int i,string answer,int rightanswer)	//��ͳ�ƽ��������û�
{
	int t=0;
	Data dat;
	language lan;
	if (answer == "q")  //����û�����q���������������������Ŀ�ĸ���
	{
		i = n;
		lan.result(t,boundadry);		//��ʾ���
	}
	int ans;
	ans = atoi(answer.c_str());
	t=dat.record(ans,rightanswer);

	if(i==n-1)		//��Ŀȫ���������������Ŀ�ĸ���
		lan.result(t,boundadry);		//��ʾ���
	return i;
}
int main()
{
	srand((unsigned)time(NULL));
	int i;
	scan();		//�ú����������û���������ȡ��������
	cin >> n; //�û�������Ŀ����
	for (i = 0; i < n; i++)
	{
		string equation = generateExpression(i + 1);
		int rightanswer = calculateResult(equation);//���ڼ������ɵ�����ʽ�Ľ��
		string answer;
		cin >> answer;		//�û������
		i=print(n,i,answer, rightanswer);		//��ͳ�ƽ��������û�
	}
	return 0;
}