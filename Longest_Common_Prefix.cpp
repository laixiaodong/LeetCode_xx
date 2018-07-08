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
	string longestCommonPrefix(vector<string>& strs) {
		string result = "";
		int size = strs.size();
		if (!size)
			return result;
		int num = 0;
		while (num<strs[0].size()) {
			for (int i = 0; i < size; i++) {
				if (strs[i].size() < num) {
					return result;
				}
				if (strs[i][num] != strs[0][num]) {
					return result;
				}
			}
			result.push_back(strs[0][num]);
			num++;
		}
		return result;
	}
};