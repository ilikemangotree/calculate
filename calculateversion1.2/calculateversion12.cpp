#include "calculateversion12.h"
#include "language.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;

char calculateversion2::creat_symbol()   // �������

{

    int n = rand()%4;

    char sym;

    switch(n)

    {

        case 0: sym='+';break;

        case 1: sym='-';break;

        case 2: sym='*';break;

        case 3: sym='/';break;

    }

return sym;

}

string calculateversion2::bracket(string n)   // �������

{

    int random=rand()%2;

    if (random==1)

    {

        n='('+n+')';

    }

    return n; 

}


string calculateversion2::int_str(int number)   // ����ת�ַ���

{

    char str[1];

    itoa(number,str,10);

    string i_s = str;

    return i_s;

}


string calculateversion2::connect(string str1,string str2,char a)   // �������������

{

    string equ = str1+a+str2;

    return equ;

}


string calculateversion2::InfixToPostfix(string infix)   // ����׺���ʽת���ɺ�׺���ʽ

{

    char current = 0;

    string postfix;//��׺���ʽ



    stack<char> mark;//����ջ



    map<char,int> priority;//�������ȼ�

    priority['+'] = 0;

    priority['-'] = 0;

    priority['*'] = 1;

    priority['/'] = 1;



    for(int i = 0;i < infix.size(); ++i)

    {

        current = infix[i];

        switch(current)

        {

            case '0':case '1':case '2':case '3':case '4':case '5':

            case '6':case '7':case '8':case '9':case '.':

                postfix.push_back(current);//����ֱ��д��

                break;

            case '+':case '-':case '*':case '/':

                //����������ǰһ��������ż�˵��ǰһ������������ϣ���#��ʶ

                if(infix[i-1] != ')')

                    postfix.push_back('#');

                //�������ջ�ǿգ����Ƚ�Ŀǰ������ջ���������ȼ������ڵ��ڳ�ջ(��д������ַ���)��

                //ֱ������ȫ����ջ����������'('���ߴ���ջ�����ŵ����ȼ�

                if(!mark.empty())

                {

                    char tempTop = mark.top();

                    while(tempTop != '(' && priority[current] <= priority[tempTop])

                    {

                        postfix.push_back(tempTop);

                        mark.pop();

                        if(mark.empty())

                            break;

                        tempTop = mark.top();

                    }

                }

                mark.push(current);//�·�����ջ

                break;

            case '(':

                if(infix[i-1] >= '0' && infix[i-1] <= '9')// for expression 2-5*2(6/2)

                {

                    postfix.push_back('#');

                    mark.push('*');

                }

                mark.push(current);

                break;

            case ')':

                postfix.push_back('#');//������˵��ǰ������������ɣ���ʶһ��

                while(mark.top() != '(')

                {

                    postfix.push_back(mark.top());

                    mark.pop();

                }

                mark.pop();//�����ų�ջ

                break;

            default:

                break;//���������ַ�

        }

    }

    if(infix[infix.size()-1] != ')')

        postfix.push_back('#');//��׺���ʽ���һ����������Ҫ����#��

    while(!mark.empty())//���ջ�ǿգ�ȫ����ջ��д������ַ���

    {

        postfix.push_back(mark.top());

        mark.pop();

    }

    return postfix;

}

float calculateversion2::posfixCompute(string s)   // �����׺���ʽ

{

    stack<float> tempResult;



    string strNum;

    float currNum = 0;



    float tempNum = 0;

    for(string::const_iterator i = s.begin(); i != s.end(); ++i)

    {

        switch(*i)

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


void calculateversion2::result(int k,int t,char boundary[][200])   //��ʾ��� 

{
		cout<<boundary[2]<<t<<endl;
		cout<<boundary[3]<<endl;
		   

}


float calculateversion2::expressionCalculate(string s)   // ���ʽ����

{

    return posfixCompute(InfixToPostfix(s));

}


int calculateversion2::record(float answer,float input,char boundary[][200])    //��¼��ȷ����

{

	int t=0;

	if(answer==input) t++;

	return t;

}
