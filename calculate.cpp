#include "calculate.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void calculate::A1()
{
	int d1,d2,d3,d4,c1,c2,c3,n,i,j;            //d1�����һ�����֣�c1�����һ�����ţ��Դ����� 
	srand((unsigned)time(NULL));             //�������������Ĺؼ� 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		d1=rand()%10+1;                      //1~10������� 
		d2=rand()%10+1;
		d3=rand()%10+1;
		d4=rand()%10+1;
		for(j=0;;j++)                         //+��-��*��/����� 
		{
			c1=rand()%6+42;
			if(c1!=44&&c1!=46)break;
		}
		for(j=0;;j++)
		{
			c2=rand()%6+42;
			if(c2!=44&&c2!=46)break;
		}
		for(j=0;;j++)
		{
			c3=rand()%6+42;
			if(c3!=44&&c3!=46)break;
		}
		cout<<d1<<char(c1)<<d2<<char(c2)<<d3<<char(c3)<<d4<<'='<<endl;   //�����ʽΪA1 
	}
}
void calculate::B1()
{
		int d1,d2,d3,d4,c1,c2,c3,n,i,j;            //d1�����һ�����֣�c1�����һ�����ţ��Դ����� 
	srand((unsigned)time(NULL));             //�������������Ĺؼ� 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		d1=rand()%10+1;                      //1~10������� 
		d2=rand()%10+1;
		d3=rand()%10+1;
		d4=rand()%10+1;
		for(j=0;;j++)                         //+��-��*��/����� 
		{
			c1=rand()%6+42;
			if(c1!=44&&c1!=46)break;
		}
		for(j=0;;j++)
		{
			c2=rand()%6+42;
			if(c2!=44&&c2!=46)break;
		}
		for(j=0;;j++)
		{
			c3=rand()%6+42;
			if(c3!=44&&c3!=46)break;
		}
		cout<<'('<<d1<<char(c1)<<d2<<')'<<char(c2)<<d3<<char(c3)<<d4<<'='<<endl;   //�����ʽΪA1 
	}
}
void calculate::B3()
{
		int d1,d2,d3,d4,c1,c2,c3,n,i,j;            //d1�����һ�����֣�c1�����һ�����ţ��Դ����� 
	srand((unsigned)time(NULL));             //�������������Ĺؼ� 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		d1=rand()%10+1;                      //1~10������� 
		d2=rand()%10+1;
		d3=rand()%10+1;
		d4=rand()%10+1;
		for(j=0;;j++)                         //+��-��*��/����� 
		{
			c1=rand()%6+42;
			if(c1!=44&&c1!=46)break;
		}
		for(j=0;;j++)
		{
			c2=rand()%6+42;
			if(c2!=44&&c2!=46)break;
		}
		for(j=0;;j++)
		{
			c3=rand()%6+42;
			if(c3!=44&&c3!=46)break;
		}
		cout<<d1<<char(c1)<<'('<<d2<<char(c2)<<d3<<')'<<char(c3)<<d4<<'='<<endl;   //�����ʽΪA1 
	}
}
void calculate::C1()
{
		int d1,d2,d3,d4,c1,c2,c3,n,i,j;            //d1�����һ�����֣�c1�����һ�����ţ��Դ����� 
	srand((unsigned)time(NULL));             //�������������Ĺؼ� 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		d1=rand()%10+1;                      //1~10������� 
		d2=rand()%10+1;
		d3=rand()%10+1;
		d4=rand()%10+1;
		for(j=0;;j++)                         //+��-��*��/����� 
		{
			c1=rand()%6+42;
			if(c1!=44&&c1!=46)break;
		}
		for(j=0;;j++)
		{
			c2=rand()%6+42;
			if(c2!=44&&c2!=46)break;
		}
		for(j=0;;j++)
		{
			c3=rand()%6+42;
			if(c3!=44&&c3!=46)break;
		}
		cout<<'('<<d1<<char(c1)<<d2<<')'<<char(c2)<<'('<<d3<<char(c3)<<d4<<')'<<'='<<endl;   //�����ʽΪA1 
	}
}

