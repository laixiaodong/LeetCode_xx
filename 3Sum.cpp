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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<int>pos, neg;
		vector<vector<int>> result;
		int zero = 0;
		sort(nums.begin(), nums.end());
		vector<int>::iterator iter = nums.begin();
		for (; iter != nums.end(); iter++) {
			if (*iter > 0) pos.push_back(*iter);
			else if (*iter == 0) { zero++; pos.push_back(*iter); }
			else neg.push_back(*iter);
		}
		if (zero >= 3)
			result.push_back({ 0,0,0 });
		int last = -1, first = -1;
		for (int u = 0; u < pos.size(); u++) {
			if (!pos[u])
				continue;
			last = 1;
			if (first == pos[u])
				continue;
			int i = 0, j = neg.size() - 1;
			while (i < j) {
				if (neg[i] + neg[j] == -pos[u]) {
					if (last == neg[i])
					{
						i++;
						j--;
						continue;
					}
					result.push_back({ pos[u] ,neg[j],neg[i] });
					last = neg[i];
					i++;
					j--;

				}
				else if (neg[i] + neg[j] > -pos[u])
					j--;
				else
					i++;

			}
			first = pos[u];
		}
		first = 1;
		for (int u = 0; u < neg.size(); u++) {
			last = -1;
			if (first == neg[u])
				continue;
			int i = 0, j = pos.size() - 1;
			while (i < j) {
				if (pos[i] + pos[j] == -neg[u]) {
					if (last == pos[i])
					{
						i++;
						j--;
						continue;
					}
					result.push_back({ neg[u] ,pos[j],pos[i] });
					last = pos[i];
					i++;
					j--;
				}
				else if (pos[i] + pos[j] > -neg[u])
					j--;
				else
					i++;
			}
			first = neg[u];
		}
		return result;
	}
};
/*int main() {
	vector<int> nums = {-2,0,0,2,2};
	Solution().threeSum(nums);
	return 0;
}*/