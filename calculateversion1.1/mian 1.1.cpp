#include<iostream>

#include<stdlib.h>

#include<time.h>

#include<string.h>

#include "calculate1.h"

using namespace std;

int main()

{

	srand((unsigned)time(NULL));

    calculate1 cal;

    char ch;

	ch=cal.choice(); 

	int N,i;

	cin>>N;

	int d[4],c[3],count=0,fenshu[2]={0,1};

	for(i=0;i<N;i++)

	{
	    cal.randomd(d);
	    cal.randomc(c);
	    cal.A1(d,c,fenshu); 

	    if(fenshu[0]%fenshu[1]==0)                                               //�����һ���г��� ������������ 
        
		    cout<<fenshu[0]/fenshu[1]<<endl;
        
		else
	    {
		    cout<<fenshu[0]<<'/'<<fenshu[1]<<endl;
        }
        
		if(ch=='a')

	    {

			cout<<"��������Ĵ𰸣�"<<endl;

		}

	    else if(ch=='b')

		{

			 cout<<"Please enter your answer :"<<endl;

		}

		char answer[20];
		
		int ans[2]={1,1},len,k,j,h,flag=0;
	
		
		cin>>answer;
		
		len=strlen(answer);
		
		for(j=0,h=0;j<=len;)
		{
	
		
		    if(answer[0]=='-')
		    {
		    	flag=1;
		    	j++;
		    	answer[0]='+';
			}
		        
		
		    int t=0;
		
		    while(answer[j]>='0'&&answer[j]<='9')
		    {
			    t=t*10+answer[j]-'0';
			    j++;
		    }	    
		    ans[h]=t;
		    h++;
			j++;
			
	    }
	    
	    if(flag==1) ans[0]=-ans[0];

	        if(fenshu[0]%fenshu[1]==0) 
			{                                              //�����һ���г��� ������������        
				if(ans[0]==fenshu[0]/fenshu[1]) 
				    count++; 
			}
			
			if(fenshu[0]%fenshu[1]!=0) 
		    {
			    if(ans[0]==fenshu[0])
			        {   
			    		if(ans[1]==fenshu[1]) 
						    count++;
					}
		    }         	        
		    if(ch=='q')break;
			
		fenshu[0]=0;
		fenshu[1]=1;	

	}

    if(ch=='a') 

	{

		cout<<"�ش���ȷ�ĵ�����Ϊ ��"<<endl;

	}

	else if(ch=='b') 

    {

		cout<<"The number of correct answers are:"<<endl;

	}

	cout<<count<<endl; 

	return 0;

	

}
