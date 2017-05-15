#include<iostream>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
#include <locale>
#include "data.h"
#include "language.h"
#include "File.h"
using namespace std;
char boundadry[20][200];
int n;
void writefile(char *path,string equ, string answer, int rightanswer, char *boundadry)//�����ս��д���ļ���д�����ݰ������û��������Ŀ����ÿ�����ɵı��ʽ����ȷ�𰸡��û�����Ĵ𰸣����浽�������еڶ�������ָ����·����

{
	File f;
	f.outputfile(path, equ, answer, rightanswer,boundadry);
}
void writefile(char *path, char *boundadry, int n)//writefile����������
{
	File f;
	f.outputfile(path, boundadry, n);
}
int readFile(char *p)//��ȡ�û�Ҫ�����Ŀ����
{
	File f;
	n=f.inputcount(p);
	return n;
}
void scan()		//�ú����������û���������ȡ��������
{
	language lan;
	lan.languagelist(boundadry);
	lan.languagechoice(boundadry);
}
string generateExpression(int i,char *p)		//������������ʽ
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
	string str_i;
	str_i = dat.int_str(i);
	equation = "(" + str_i + ")" + equation + "=";
	cout << equation << endl;       //��������ʽ 
	cout << boundadry[1] ;
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
	int ans;
	ans = atoi(answer.c_str());
	t=dat.record(ans,rightanswer);
	return t;
}
int main(int argc, char *argv[])
{
	fstream file;
	file.open(argv[2]);
	srand((unsigned)time(NULL));
	int i;
	n = readFile(argv[1]); //�û�������Ŀ����
	scan();		//�ú����������û���������ȡ��������
	cout << boundadry[0]<< n << endl;
	cout << "========================" << endl << endl;
	writefile(argv[2], boundadry[0], n);
	int t; 
	for (i = 0; i < n; i++)
	{
		string equation = generateExpression(i + 1,argv[2]);
		file << equation << endl;       //��������ʽ 
		int rightanswer = calculateResult(equation);//���ڼ������ɵ�����ʽ�Ľ��
		string answer;
		cin >> answer;		//�û������
		if (answer == "q")		//����û�����q���������������������Ŀ�ĸ���
			break;
		t=print(n,i,answer, rightanswer);		//��ͳ�ƽ��������û�
		cout << boundadry[2] << rightanswer << endl;
		cout << "========================" << endl << endl;
		writefile(argv[2], equation, answer, rightanswer, boundadry[2]);
	}
	cout << boundadry[3] << t << endl;
	cout << boundadry[4] << endl;
	file.close();
	return 0;
}