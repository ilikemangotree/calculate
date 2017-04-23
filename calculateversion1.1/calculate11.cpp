#include "calculate1.h"

#include<iostream>

#include<stdlib.h>

#include<time.h>

using namespace std;

char calculate1::choice()

{

	cout<<"Please choose the language that you need:(a.Simple Chinese; b.English)"<<endl;                                 //2种语言的切换     

	int i;

	char choice;

	for(i=0;;i++)

	{

		cin>>choice;

	    if(choice=='a')

	        {cout<<"请输入你所想要的题目数(你可以输入'q'则结束程序)："<<endl;break;}

	    else if(choice=='b') 

		    {cout<<"Please enter the number of texts you want(You can enter'q'to end the program):"<<endl;break;}

		else

		    {cout<<"输入不当，请重新选择选项/Please select the option again if it is wrong"<<endl;continue;}

	}

	return choice;

}

int calculate1::randomd(int d[])

{

		d[0]=rand()%10+1;                      //整数数字随机函数 

	    d[1]=rand()%10+1;

	    d[2]=rand()%10+1;

	    d[3]=rand()%10+1;

}

int calculate1::randomc(int c[])

{

	int j;

	for(j=0;;j++)                         //+，-，*，/的随机 

	{

		c[0]=rand()%6+42;

		if(c[0]!=44&&c[0]!=46)break;

	}

	    for(j=0;;j++)

	    {

		    c[1]=rand()%6+42;

		    if(c[1]!=44&&c[1]!=46)break;

	    }

	    for(j=0;;j++)

	    {

		    c[2]=rand()%6+42;

		    if(c[2]!=44&&c[2]!=46)break;

	    }

}

int calculate1::gcd(int x,int y)

{

	int r=1,t;

	if(x>y){t=x;x=y;y=t;}

	while(r!=0)

	{

		r=y%x;

		y=x;

		x=r;

	}

}

int calculate1::A1(int d[],int c[],int fenshu[])

{

	int j;

	cout<<d[0]<<char(c[0])<<d[1]<<char(c[1])<<d[2]<<char(c[2])<<d[3]<<'='<<endl;

	int k=0;

	for(j=0;j<3;j++)

	{

		if(c[j]==45)  // '-'

		{

			d[j+1]=-d[j+1];

			c[j]=43;

		}

	}		

	for(j=0;j<3;j++)

	{

		

		if(c[0]==47&&c[2]==47&&c[1]==43)

		{

			fenshu[0]=d[0]*d[3]+d[2]*d[1];

			fenshu[1]=d[1]*d[3];

		    c[1]=0;

			break;

		}

		if(c[j]==42)

		{	

		    d[j+1]*=d[j];

		    d[j]=0;

		    c[j]=43;

		}

		 

		if(c[j]==47)

		{

			

			if(k==0)fenshu[0]=d[j];

			fenshu[1]*=d[j+1];

			d[j+1]=d[j];

			d[j]=0;

			k++;                                //防止分子被重置 

			if(c[j+1]==42)

			{

				fenshu[0]*=d[j+2];
				j++;
				if(c[j+1]==42)
				{
					fenshu[0]*=d[j+2];
					j++;
				 } 
			}

		}

    }

	for(j=0;j<3;j++)

	{	

		if(c[j]==43)

			{

				if(j==0)

				    fenshu[0]+=d[0]*fenshu[1]; 

				fenshu[0]+=d[j+1]*fenshu[1];			

			}		

	}

	int r=1,x=fenshu[0],y=fenshu[1],t;

	if(x>y){t=x;x=y;y=t;}

	while(r!=0)

	{
		r=y%x;
		y=x;
		x=r;
	}

	fenshu[0]=fenshu[0]/y;

	fenshu[1]=fenshu[1]/y;
	if(fenshu[1]<0)
	{
		fenshu[1]=-fenshu[1];
		fenshu[0]=-fenshu[0];
	}
	

	  

 

}


