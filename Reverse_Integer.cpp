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
	int reverse(int x) {
		vector<int>a;
		int num = 0;
		bool flag = false;
		if (x < 0) {
			flag = true;
			x = -x;
		}
		while (x) {
			num = x % 10;
			a.push_back(num);
			x = x / 10;
		}
		int result = 0;
		for (int i = 0; i < a.size(); i++) {
			if ((unsigned)(result) > INT_MAX / 10) {
				return 0;
			}
			result = result * 10 + a[i];
			cout << result << endl;
		}
		return flag ? -result : result;
	}
};