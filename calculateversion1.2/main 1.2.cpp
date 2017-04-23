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
	calculateversion2 cal;///////////// 
	
	language lan;//////////////// 

    srand(unsigned(time(0)));

    int count,i,j,n1,n2,exchange,t=0,f,temp2;/////////////// 
    
    char boundary[20][200];/////////// 

    char location[100]=""; ////////////// 

    string str_n1,str_n2,temp;/////////// 

    char symbol,end;/////////// 

    char languagein[50];///////// 
    
    lan.languagelist();
    
    lan.languagechoice(boundary);
    

    cin>>count;

    string equation[10000];///////// 

    float *answer = new float[10000];////////// 

    float *input = new float[10000];/////////// 

    for (i = 0; i < count; i++)

    {

        n1=rand()%10+1;   //随机数字 

        n2=rand()%10+1;   //随机数字 

        symbol=cal.creat_symbol();  //随机生成字符 

        str_n1=cal.int_str(n1);    //将数字转换为字符串 

        str_n2=cal.int_str(n2);    //将数字转换为字符串 

        equation[i]=cal.connect(str_n1,str_n2,symbol);     //连接数字和符号形成方程式 

        for (j = 0; j < 2; j++)

        {            

            str_n1=cal.bracket(equation[i]);   // 每2个数字和一个符号就随机在两端加一个括号 

            n2=rand()%11;

            str_n2=cal.int_str(n2);       

            exchange=rand()%2;     // 对字符串位置进行随机交换

            if (exchange==1)

            {

                temp=str_n1;

                str_n1=str_n2;

                str_n2=temp;

            }

            symbol=cal.creat_symbol();

            equation[i]=cal.connect(str_n1,str_n2,symbol);  //将新生成的数字与字符连接上原来的字符串上 

        }

        cout<<"("<<i+1<<"):"<<equation[i]<<'=';      //生成运算式 

        cin>>input[i];                           //用户输入答案 

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

