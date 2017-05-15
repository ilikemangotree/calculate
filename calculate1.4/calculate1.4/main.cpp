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
void writefile(char *path,string equ, string answer, int rightanswer, char *boundadry)//将最终结果写入文件，写入内容包括：用户输入的题目数，每个生成的表达式、正确答案、用户输入的答案，保存到命令行中第二个参数指定的路径。

{
	File f;
	f.outputfile(path, equ, answer, rightanswer,boundadry);
}
void writefile(char *path, char *boundadry, int n)//writefile函数的重载
{
	File f;
	f.outputfile(path, boundadry, n);
}
int readFile(char *p)//读取用户要求的题目数量
{
	File f;
	n=f.inputcount(p);
	return n;
}
void scan()		//该函数用于与用户交互，获取输入数据
{
	language lan;
	lan.languagelist(boundadry);
	lan.languagechoice(boundadry);
}
string generateExpression(int i,char *p)		//用于生成运算式
{
	int n1, n2;
	Data dat;
	n1 = dat.randomNumber();	//随机数字
	n2 = dat.randomNumber();	//随机数字
	char sign;
	sign = dat.randomOperation();	//随机生成字符 
	string str_n1, str_n2, temp;
	str_n1 = dat.int_str(n1);	//将数字转换为字符串 
	str_n2 = dat.int_str(n2);	//将数字转换为字符串 
	string equation;
	equation = dat.connect(str_n1, str_n2, sign);	//连接2个数字和1个符号 
	for (int j = 0; j < 2; j++)
	{
		str_n1 = dat.bracket(equation);   // 每2个数字和一个符号就随机在两端加一个括号 
		n2 = rand() % (10-1+1)+1;
		str_n2 = dat.int_str(n2);
		int exchange;
		exchange = rand() % 2;     // 对字符串位置进行随机交换
		if (exchange == 1)
		{
			temp = str_n1;
			str_n1 = str_n2;
			str_n2 = temp;
		}
		sign = dat.randomOperation();
		equation = dat.connect(str_n1, str_n2, sign);  //把那2个数字和1个符号看做旧的的字符串，将新生成的数字与字符连接上旧的的字符串上
	}
	string str_i;
	str_i = dat.int_str(i);
	equation = "(" + str_i + ")" + equation + "=";
	cout << equation << endl;       //生成运算式 
	cout << boundadry[1] ;
	return equation;
}
int calculateResult(string n)	//用于计算生成的运算式的结果()
{
	Data dat;
	return dat.expressionCalculate(n);
}
int print(int n,int i,string answer,int rightanswer)	//将统计结果输出给用户
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
	n = readFile(argv[1]); //用户输入题目数量
	scan();		//该函数用于与用户交互，获取输入数据
	cout << boundadry[0]<< n << endl;
	cout << "========================" << endl << endl;
	writefile(argv[2], boundadry[0], n);
	int t; 
	for (i = 0; i < n; i++)
	{
		string equation = generateExpression(i + 1,argv[2]);
		file << equation << endl;       //生成运算式 
		int rightanswer = calculateResult(equation);//用于计算生成的运算式的结果
		string answer;
		cin >> answer;		//用户输入答案
		if (answer == "q")		//如果用户输入q键则结束程序并且输出答对题目的个数
			break;
		t=print(n,i,answer, rightanswer);		//将统计结果输出给用户
		cout << boundadry[2] << rightanswer << endl;
		cout << "========================" << endl << endl;
		writefile(argv[2], equation, answer, rightanswer, boundadry[2]);
	}
	cout << boundadry[3] << t << endl;
	cout << boundadry[4] << endl;
	file.close();
	return 0;
}