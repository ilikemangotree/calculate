#ifndef CALCULATE1_H
#define CALCULATE1_H

class calculate2
{
	public:
		int A1(int d[],int c[],int fenshu[]);
	    int B1(int d[],int c[],int fenshu[]);
	    int B3(int d[],int c[],int fenshu[]);
	    int C1(int d[],int c[],int fenshu[]);
	    int randomd(int d[]);
	    int randomc(int c[]);
	    int calculate(int d[],int c[]);
	    char choice();
		int gcd(int x,int y); 
	private:
		int d[4];
		int c[3];
		
		
};
#endif
