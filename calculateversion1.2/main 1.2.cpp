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

int main()

{
	calculateversion2 cal;
	
	language lan;

    srand(unsigned(time(0)));

    int count,i,j,n1,n2,exchange,t=0,f,temp2;
    
    char boundary[20][200];

    char location[100]=""; 

    string str_n1,str_n2,temp;

    char symbol,end;

    char languagein[50];
    
    lan.languagelist();
    
    lan.languagechoice(boundary);
    

    cin>>count;

    string equation[count];

    float *answer = new float[count];

    float *input = new float[count];

    for (i = 0; i < count; i++)

    {

        n1=rand()%11;

        n2=rand()%11;

        symbol=cal.creat_symbol();

        str_n1=cal.int_str(n1);

        str_n2=cal.int_str(n2);

        equation[i]=cal.connect(str_n1,str_n2,symbol);

        for (j = 0; j < 2; j++)

        {           

            str_n1=equation[i];

            str_n1=cal.bracket(equation[i]);

            n2=rand()%11;

            str_n2=cal.int_str(n2);

            // 对字符串位置进行随机交换

            exchange=rand()%2;

            if (exchange==1)

            {

                temp=str_n1;

                str_n1=str_n2;

                str_n2=temp;

            }

            symbol=cal.creat_symbol();

            equation[i]=cal.connect(str_n1,str_n2,symbol);

        }

        cout<<"("<<i+1<<"):"<<equation[i]<<'=';

        cin>>input[i];

        answer[i]=cal.expressionCalculate(equation[i]);

        //四舍五入保留两位小数

        temp2=(int)(answer[i]*100+0.5f);

        answer[i]=(float)temp2/100;

        //正确题目数量和是否正确的提示

        t+=cal.record(answer[i],input[i],boundary);

        //作答结束后调用函数显示结果 
        int k=0;

		if(i==count-1||input[i]=='q')
		{
		    cal.result(k,t,boundary);
		    break;
		}
	}

    delete [] answer;

    delete [] input;

return 0;
}

