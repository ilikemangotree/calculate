#include "calculate.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	calculate cal;
	int k,N;        //NΪ������Ŀ������kΪ���ѡȡ��Ŀ���� 
	srand((unsigned)time(NULL));
	k=rand()%4; 
	switch(k); 
	{
		case 0:cal.A1();break;
		case 1:cal.B1();break;
		case 2:cal.B3();break;
		case 3:cal.C1();break;
	 } 
	return 0;
}
