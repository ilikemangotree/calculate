#pragma once
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class Random
{
protected:
	int num;		//产生的随机数
	char sym;		//产生的随机字符
public:
	virtual int random()=0;//创造虚函数，建立公共接口
};
class RandomNumber :public Random//用于随机生成数字
{
public:
	int random();
};
class RandomOperation :public Random//用于随机生成运算符
{
public:
	int random();
};

class RandomFactory		//创建工厂
{
public:
	Random *randomrandom(string name)	//根据需求来选择产生什么样的产品（生产随机数/随机符号）
	{
		if (name == "rannum")
			return new RandomNumber;
		else if (name == "ranope")
			return new RandomOperation;
	}
};