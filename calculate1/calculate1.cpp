#include "calculate1.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void calculate1::A1()
{
	int d1,d2,d3,d4,c1,c2,c3,i,j;            //d1代表第一个数字，c1代表第一个符号，以此类推 
	srand((unsigned)time(NULL));             //这个是随机函数的关键 
	d1=rand()%10+1;                      //1~10的随机数 
	d2=rand()%10+1;
	d3=rand()%10+1;
	d4=rand()%10+1;
	for(j=0;;j++)                         //+，-，*，/的随机 
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
	cout<<d1<<char(c1)<<d2<<char(c2)<<d3<<char(c3)<<d4<<'='<<endl;   //输出格式为A1 
}
void calculate1::B1()
{
	int d1,d2,d3,d4,c1,c2,c3,i,j;            //d1代表第一个数字，c1代表第一个符号，以此类推 
	srand((unsigned)time(NULL));             //这个是随机函数的关键 
	d1=rand()%10+1;                      //1~10的随机数 
	d2=rand()%10+1;
	d3=rand()%10+1;
	d4=rand()%10+1;
	for(j=0;;j++)                         //+，-，*，/的随机 
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
	cout<<'('<<d1<<char(c1)<<d2<<')'<<char(c2)<<d3<<char(c3)<<d4<<'='<<endl;   //输出格式为A1 
}
void calculate1::B3()
{
int d1,d2,d3,d4,c1,c2,c3,i,j;            //d1代表第一个数字，c1代表第一个符号，以此类推 
    srand((unsigned)time(NULL));             //这个是随机函数的关键 
	d1=rand()%10+1;                      //1~10的随机数 
	d2=rand()%10+1;
	d3=rand()%10+1;
	d4=rand()%10+1;
	for(j=0;;j++)                         //+，-，*，/的随机 
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
	cout<<d1<<char(c1)<<'('<<d2<<char(c2)<<d3<<')'<<char(c3)<<d4<<'='<<endl;   //输出格式为A1 
}
void calculate1::C1()
{
	int d1,d2,d3,d4,c1,c2,c3,i,j;            //d1代表第一个数字，c1代表第一个符号，以此类推 
	srand((unsigned)time(NULL));             //这个是随机函数的关键 
	d1=rand()%10+1;                      //1~10的随机数 
	d2=rand()%10+1;
	d3=rand()%10+1;
	d4=rand()%10+1;
	for(j=0;;j++)                         //+，-，*，/的随机 
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
	cout<<'('<<d1<<char(c1)<<d2<<')'<<char(c2)<<'('<<d3<<char(c3)<<d4<<')'<<'='<<endl;   //输出格式为A1 

}
