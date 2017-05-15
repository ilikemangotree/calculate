#pragma once
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class File
{
private:
	char *inputfile;		//读取文件的相对路径
	int n;			//从读取文件中读取的生成题目的个数
	char *outpath;		//写入文件的相对路径

public:
	int inputcount(char *inputfile);
	void outputfile(char *path,string equ,string answer,int rightanswer,char *boundadry);
	void outputfile(char *path, char *bourdadry, int n);



protected:
};
#endif