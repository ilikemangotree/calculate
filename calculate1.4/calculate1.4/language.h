#pragma once
#pragma once
#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stack>
#include <map> 
#include <fstream>
class language
{
private:
	char boundadry[20][200];		//���ڴ洢���Խ���ĸ������
	char line[100] = "";			//�洢�����б�
	char path[100] = "";			//�洢�û�Ҫ������ԣ����洢�����·��
public:
	void languagelist(char boundadry[20][200]);			//�����б�
	void languagechoice(char boundadry[20][200]);			//�û�ѡ������



protected:
};
#endif