#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	cout<<"Please choose the language that you need:(a.Simple Chinese; b.English)"<<endl;                                 //2�����Ե��л�     
	int i;
	char choice;
	for(i=0;;i++)
	{
		cin>>choice;
	    if(choice=='a')
	        {cout<<"������������Ҫ����Ŀ����"<<endl;break;}
	    else if(choice=='b') 
		    {cout<<"Please enter the number of texts you want:"<<endl;break;}
		else
		    {cout<<"���벻����������ѡ��ѡ��/Please select the option again if it is wrong"<<endl;continue;}
	}
	int k,N;                                     //NΪ������Ŀ������kΪ���ѡȡ��Ŀ���� 
	srand((unsigned)time(NULL));
    cin>>N;
	for(i=0;i<N;i++)
	{
		int d[4],c[3],j;
		d[0]=rand()%10+1;                      //��������������� 
	    d[1]=rand()%10+1;
	    d[2]=rand()%10+1;
	    d[3]=rand()%10+1;
	    for(j=0;;j++)                         //+��-��*��/����� 
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
	    k=rand()%4;                          //���4�ֺ������� 
	    switch(k)
	    {
		    case 0 : cout<<d[0]<<char(c[0])<<d[1]<<char(c[1])<<d[2]<<char(c[2])<<d[3]<<'='<<endl;break;
		    case 1 : cout<<'('<<d[0]<<char(c[0])<<d[1]<<')'<<char(c[1])<<d[2]<<char(c[2])<<d[3]<<'='<<endl;break;
		    case 2 : cout<<d[0]<<char(c[0])<<'('<<d[1]<<char(c[1])<<d[2]<<')'<<char(c[2])<<d[3]<<'='<<endl;break;
		    case 3 : cout<<'('<<d[0]<<char(c[0])<<d[1]<<')'<<char(c[1])<<'('<<d[2]<<char(c[2])<<d[3]<<')'<<'='<<endl;break;
	     }
		if(k==0)
		{ 
	        for(j=0;j<3;j++)
		    {
			    int answer[4]={0};
			    if(c[j]==42)answer[j]=d[j]*d[j+1];
			    else if(c[j]==)
		    } 
	}
	return 0;
}
