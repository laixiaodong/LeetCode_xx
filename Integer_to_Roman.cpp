/*
The project was established to solve the leetcode problem.
The author is Xu Xing and the file name is the name of the issue.
2018 / 2
*/
#include "stdafx.h"
#include <map>
#include <iostream>   
#include <algorithm> 
#include<stdio.h>//定义输入/输出函数
#include<stdlib.h>//定义杂项函数及内存分配函数
#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		map<int, string> correspond;
		correspond[1] = "I";
		correspond[5] = "V";
		correspond[10] = "X";
		correspond[50] = "L";
		correspond[100] = "C";
		correspond[500] = "D";
		correspond[1000] = "M";

		for (int i = 1; i <= 1000;) {
			correspond[2 * i] = correspond[i] + correspond[i];
			correspond[3 * i] = correspond[i] + correspond[i] + correspond[i];
			correspond[4 * i] = correspond[i] + correspond[5 * i];
			correspond[6 * i] = correspond[5 * i] + correspond[i];
			correspond[7 * i] = correspond[5 * i] + correspond[i] + correspond[i];
			correspond[8 * i] = correspond[5 * i] + correspond[i] + correspond[i] + correspond[i];
			correspond[9 * i] = correspond[i] + correspond[10 * i];
			i *= 10;
		}
		string result = "";
		int count = 1;
		while (num)
		{
			int yushu = num % 10;
			result = correspond[yushu*count] + result;
			num = num / 10;
			count = 10 * count;
		}
		return result;
	}
};