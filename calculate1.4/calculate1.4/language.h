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
public:
	void languagelist(char boundadry[20][200]);			//语言列表
	void languagechoice(char boundadry[20][200]);			//用户选择语言
	void result(int t,char boundadry[20][200]);		//显示用户答对题目个数



protected:
};
#endif
