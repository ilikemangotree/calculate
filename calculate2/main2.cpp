#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "calculate2.h"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
    calculate2 cal;
    char ch;
	ch=cal.choice(); 
	int N,i;
	cin>>N;
	int d[4],c[3],count=0,fenshu[2]={1,1};
	for(i=0;i<N;i++)
	{
	    cal.randomd(d);
	    cal.randomc(c);
 	    int k;
        k=rand()%4;
	    switch(k)                          //随机4种函数类型
	    {
		    case 0:cal.A1(d,c,fenshu);break;
		    case 1:cal.B1(d,c,fenshu);break;
		    case 2:cal.B3(d,c,fenshu);break;
		    case 3:cal.C1(d,c,fenshu);break;
	    }
	    if(ch=='a')
	    {
			cout<<"请输入你的答案："<<endl;
		}
	    else if(ch=='b')
		{
			 cout<<"Please enter your answer :"<<endl;
		}
		int answer[2];
		cin>>answer[0];
	    if(c[0]=='/'||c[1]=='/'||c[2]=='/')
	    {
	        if(fenshu[0]%fenshu[1]==0)                                               //结果不一定有除号 ，可能是整数 
                if(answer[0]==fenshu[0]/fenshu[1])count++;
            else
		    {
			    if(answer[0]==fenshu[0])
			    {
			    	char fenhao;
			    	cin>>fenhao;
			    	if(fenhao=='/')
			    	{
			    		cin>>answer[1];
			    		if(answer[1]==fenshu[1])count++;
					}
				}
		    }         	        
        }
        else 
		    if(ch=='q')break;	
	
	}
    if(ch=='a') 
	{
		cout<<"回答正确的的题数为 ："<<endl;
	}
	else if(ch=='b') 
    {
		cout<<"The number of correct answers are:"<<endl;
	}
	cout<<count<<endl; 
	return 0;
	
}
