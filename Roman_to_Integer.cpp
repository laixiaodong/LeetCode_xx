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
	int romanToInt(string s) {
		int res = 0;
		map<char, int> m{ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
		for (int i = 0; i < s.size(); ++i) {
			if (i == 0 || m[s[i]] <= m[s[i - 1]]) 
				res += m[s[i]];
			else 
				res += m[s[i]] - 2 * m[s[i - 1]];
		}
		return res;
	}
};