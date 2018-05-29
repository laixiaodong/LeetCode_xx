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
	bool isPalindrome(int x) {
		if (x == 0)
			return true;
		if (x < 0)
			return false;
		vector<int> data;
		while (x) {
			data.push_back(x % 10);
			x = x / 10;
		}
		int size = data.size();
		for (int i = 0; i < size/2; i++) {
			if (data[i] == data[size - i - 1])
				continue;
			return false;
		}
		return true;
	}
};