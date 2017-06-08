#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
#include <iostream>
#include "data.h"
using namespace std;
string Data::bracket(string str)   // 随机括号

{
	random = rand() % 2;
	if (random == 1)
	{
		str = '(' + str + ')';
	}
	return str;

}


string Data::int_str(int number)   // 数字转字符串

{

	char str[100];
	_itoa_s(number, str, 10);
	string i_s = str;
	return i_s;

}


string Data::connect(string str1, string str2, char a)   // 连接数字运算符

{

	equ = str1 + a + str2;

	return equ;

}
int Data::expressionCalculate(string s)   // 表达式计算

{

	return posfixCompute(InfixToPostfix(s));

}
string Data::InfixToPostfix(string infix)   // 将中缀表达式转换成后缀表达式

{

	char current = 0;

	priority['+'] = 0;

	priority['-'] = 0;

	priority['*'] = 1;

	priority['/'] = 1;

	for (int i = 0; i < infix.size(); ++i)

	{

		current = infix[i];

		switch (current)

		{

		case '0':case '1':case '2':case '3':case '4':case '5':

		case '6':case '7':case '8':case '9':case '.':

			postfix.push_back(current);//数字直接写入

			break;

		case '+':case '-':case '*':case '/':

			//如果运算符的前一项不是右括号即说明前一个数字输入完毕，用#标识

			if (infix[i] != ')')

				postfix.push_back('#');

			//如果符号栈非空，即比较目前符号与栈顶符号优先级，低于等于出栈(并写入输出字符串)，

			//直至符号全部出栈或者遇到了'('或者大于栈顶符号的优先级

			if (!mark.empty())

			{

				char tempTop = mark.top();

				while (tempTop != '(' && priority[current] <= priority[tempTop])

				{

					postfix.push_back(tempTop);

					mark.pop();

					if (mark.empty())

						break;

					tempTop = mark.top();

				}

			}

			mark.push(current);//新符号入栈

			break;

		case '(':

			if (infix[i] >= '0' && infix[i] <= '9')// for expression 2-5*2(6/2)

			{

				postfix.push_back('#');

				mark.push('*');

			}

			mark.push(current);

			break;

		case ')':

			postfix.push_back('#');//右括号说明前方数字输入完成，标识一下

			while (mark.top() != '(')

			{

				postfix.push_back(mark.top());

				mark.pop();

			}

			mark.pop();//左括号出栈

			break;

		default:

			break;//忽略其他字符

		}

	}

	if (infix[infix.size() - 1] != ')')

		postfix.push_back('#');//中缀表达式最后一个是数字需要加上#。

	while (!mark.empty())//如果栈非空，全部出栈并写入输出字符串

	{

		postfix.push_back(mark.top());

		mark.pop();

	}

	return postfix;

}

int Data::posfixCompute(string s)   // 计算后缀表达式

{

	string strNum;

	int currNum = 0;

	int tempNum = 0;

	for (string::const_iterator i = s.begin(); i != s.end(); ++i)

	{

		switch (*i)

		{

		case '0':case '1':case '2':case '3':case '4':case '5':

		case '6':case '7':case '8':case '9':case '.':

			strNum.push_back(*i);

			break;

		case '+':

			tempNum = tempResult.top();

			tempResult.pop();

			tempNum += tempResult.top();

			tempResult.pop();

			tempResult.push(tempNum);

			break;

		case '-':

			tempNum = tempResult.top();

			tempResult.pop();

			tempNum = tempResult.top() - tempNum;

			tempResult.pop();

			tempResult.push(tempNum);

			break;

		case '*':

			tempNum = tempResult.top();

			tempResult.pop();

			tempNum *= tempResult.top();

			tempResult.pop();

			tempResult.push(tempNum);

			break;

		case '/':

			tempNum = tempResult.top();

			tempResult.pop();

			tempNum = tempResult.top() / tempNum;

			tempResult.pop();

			tempResult.push(tempNum);

			break;

		case '#':

			currNum = atof(strNum.c_str());

			strNum.clear();

			tempResult.push(currNum);

			break;

		}

	}

	return tempResult.top();

}




int Data::record(int answer, int rightanswer)    //记录正确题数

{


	if (answer == rightanswer) rightcount++;

	return rightcount;

}
