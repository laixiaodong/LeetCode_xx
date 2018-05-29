/*
The project was established to solve the leetcode problem.
The author is Xu Xing and the file name is the name of the issue.
2018 / 2
*/
#include "stdafx.h"
#include <vector>
#include <iostream>   
#include <algorithm> 
#include<stdio.h>//定义输入/输出函数
#include<stdlib.h>//定义杂项函数及内存分配函数
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		string s = str;
		bool flag = true;
		int begin = 0;
		int result = 0;
		if (s.empty()) {
			return 0;
		}
		s.erase(0, s.find_first_not_of(" "));
		if (!isdigit(s[0]) && s[0] != '-' && s[0] != '+') {
			return 0;
		}
		if (s[0] == '-') {
			flag = false;
			begin = 1;
		}
		else if (s[0] == '+')
			begin = 1;
		for (; begin < s.length(); begin++)
		{
			if (!isdigit(s[begin]))
				return flag ? result : -result;
			if ((unsigned)(result) >(INT_MAX - s[begin] + '0') / 10) {
				cout << flag << endl;
				if (flag)
					return INT_MAX;
				return INT_MIN;
				break;
			}
			result = (s[begin] - '0') + result * 10;
		}
		return flag ? result : -result;
	}
	bool isdigit(const char c) {
		return (c >= '0' && c <= '9');
	}
};