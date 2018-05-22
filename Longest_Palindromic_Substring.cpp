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
	string longestPalindrome(string s) {
		int length = s.size();
		if (length == 1 || length ==0)
			return s;
		if (length == 2) {
			if (s[0] == s[1])
				return s;
			else
				return s.substr(0, 1);
		}
		bool p[1000][1000];
		for (int k = 0; k < 1000; k++) {
			for (int y = k; y < 1000; y++) {
				if (k == y)
					p[k][y] = true;
				else
					p[k][y] = false;
			}
		}
		for (int j = 0; j < length - 1; j++) {
			if (s[j] == s[j + 1]) {
				p[j][j + 1] = true;
			}
		}
		for (int i = 2; i < length; i++) {
			for (int j = 0; j < length - i; j++) {
				if (s[j] == s[j + i]) {
					p[j][j + i] = p[j + 1][j + i - 1];
				}
			}
		}
		int begin = 0, max = 0;
		for (int k = 0; k < length; k++) {
			for (int y = k; y < length; y++) {
				if (p[k][y]) {
					if (y - k > max) {
						begin = k;
						max = y - k;
					}
				}
			}
		}
		return s.substr(begin, max + 1);
	}
};