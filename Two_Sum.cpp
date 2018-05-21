// easy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>result;
		vector<int>::iterator it = nums.begin();
		for (; it != nums.end(); it++) {
			int a = target - *it;
			vector<int>::iterator it_1 = find(nums.begin(), nums.end(), a);
			if (it_1 != nums.end() && it != it_1) {
				result.push_back(distance(nums.begin(), it));
				result.push_back(distance(nums.begin(), it_1));
				break;
			}
		}
		return result;
	}
};


