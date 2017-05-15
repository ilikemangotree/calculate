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
	char boundadry[20][200];		//用于存储语言界面的各个语句
	char line[100] = "";			//存储语言列表
	char path[100] = "";			//存储用户要求的语言，并存储其相对路径
public:
	void languagelist(char boundadry[20][200]);			//语言列表
	void languagechoice(char boundadry[20][200]);			//用户选择语言



protected:
};
#endif