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
	char *inputfile;		//��ȡ�ļ������·��
	int n;			//�Ӷ�ȡ�ļ��ж�ȡ��������Ŀ�ĸ���
	char *outpath;		//д���ļ������·��

public:
	int inputcount(char *inputfile);
	void outputfile(char *path,string equ,string answer,int rightanswer,char *boundadry);
	void outputfile(char *path, char *bourdadry, int n);



protected:
};
#endif