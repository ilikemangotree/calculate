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

        n1=rand()%10+1;   //������� 

        n2=rand()%10+1;   //������� 

        symbol=cal.creat_symbol();  //��������ַ� 

        str_n1=cal.int_str(n1);    //������ת��Ϊ�ַ��� 

        str_n2=cal.int_str(n2);    //������ת��Ϊ�ַ��� 

        equation[i]=cal.connect(str_n1,str_n2,symbol);     //�������ֺͷ����γɷ���ʽ 

        for (j = 0; j < 2; j++)

        {            

            str_n1=cal.bracket(equation[i]);   // ÿ2�����ֺ�һ�����ž���������˼�һ������ 

            n2=rand()%11;

            str_n2=cal.int_str(n2);       

            exchange=rand()%2;     // ���ַ���λ�ý����������

            if (exchange==1)

            {

                temp=str_n1;

                str_n1=str_n2;

                str_n2=temp;

            }

            symbol=cal.creat_symbol();

            equation[i]=cal.connect(str_n1,str_n2,symbol);  //�������ɵ��������ַ�������ԭ�����ַ����� 

        }

        cout<<"("<<i+1<<"):"<<equation[i]<<'=';      //��������ʽ 

        cin>>input[i];                           //�û������ 

        answer[i]=cal.expressionCalculate(equation[i]);    

        //�������뱣����λС��

        temp2=(int)(answer[i]*100+0.5f);

        answer[i]=(float)temp2/100;

        //��ȷ��Ŀ�������Ƿ���ȷ����ʾ

        t+=cal.record(answer[i],input[i],boundary);

        //�����������ú�����ʾ��� 
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
