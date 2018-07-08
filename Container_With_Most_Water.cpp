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
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size()-1;
		int max_ = min(height[i], height[j]) * (j-i);
		while (j>i) {
			if (height[i] > height[j])
				j--;
			else
				i++;
			int more = min(height[i], height[j]) * (j - i);
			max_ = max(max_, more);
		}
		return max_;
	}
};