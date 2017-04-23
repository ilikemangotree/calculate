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
void scan()		//该函数用于与用户交互，获取输入数据
{
	language lan;
	lan.languagelist(boundadry);
	lan.languagechoice(boundadry);
}
string generateExpression(int i)		//用于生成运算式
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
	cout << "(" << i << "):" << equation << '=';      //生成运算式 
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
	if (answer == "q")  //如果用户输入q键则结束程序并且输出答对题目的个数
	{
		i = n;
		lan.result(t,boundadry);		//显示结果
	}
	int ans;
	ans = atoi(answer.c_str());
	t=dat.record(ans,rightanswer);

	if(i==n-1)		//题目全部做完后输出答对题目的个数
		lan.result(t,boundadry);		//显示结果
	return i;
}
int main()
{
	srand((unsigned)time(NULL));
	int i;
	scan();		//该函数用于与用户交互，获取输入数据
	cin >> n; //用户输入题目数量
	for (i = 0; i < n; i++)
	{
		string equation = generateExpression(i + 1);
		int rightanswer = calculateResult(equation);//用于计算生成的运算式的结果
		string answer;
		cin >> answer;		//用户输入答案
		i=print(n,i,answer, rightanswer);		//将统计结果输出给用户
	}
	return 0;
}