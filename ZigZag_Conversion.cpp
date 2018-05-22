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
#include<map>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		map<int, string> flag;
		int length = s.length();
		if (length == 1 || numRows == 1) {
			return s;
		}
		for (size_t i = 0; i < length; i++) {
			int k = i % (2 * numRows - 2);
			if (k>numRows - 1) {
				flag[2 * numRows - 2 - k].push_back(s[i]);
				//cout << "flag[" << 2 * numRows - 2 - k << "]=" << flag[2 * numRows - 2 - k] << endl;
			}
			else {
				flag[k].push_back(s[i]);
				//cout << "flag[" << k << "]=" << flag[k] << endl;
			}
		}
		map<int, string>::iterator it;
		string result = "";
		for (int i = 0; i < flag.size(); i++) {
			result = result + flag[i];
		}
		return result;
	}
};