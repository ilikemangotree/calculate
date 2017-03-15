#include "calculateversion12.h"
#include "language.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
void language::languagelist()
{
	fstream file;
	file.open("languagelist.txt");
	char line[100]="";
	while(file.getline(line,100))
	{
		cout<<line<<endl;
	}
	file.close();
}
void language::languagechoice(char boundary[][200])
{
	char path[100]="",choice[100];
	int i;
	for(i=0;;i++)
	{
		cin>>choice;
		strcat(path,choice);
		strcat(path,".txt");
		fstream file;
		file.open(path,ios::in);
		if (file.is_open())

    	{
    		int i; 
	    	for(i=0;file.getline(boundary[i],200);i++)
	    	{
	    	}
        	file.close();
        	cout<<boundary[0]<<endl;
        	break;

    	}

    	else
	   		cout<<"Sorry,your choice has not been prepared,please choice again!"<<endl;
	}
}



