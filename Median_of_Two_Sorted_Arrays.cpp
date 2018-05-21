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
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		int i = 0, a = 0, b = 0;
		int flag = 0, flag_ = 0;
		cout << "n=" << n << "m=" << m << endl;
		if (m == 0) {
			if (n % 2)
				return nums1[n / 2];
			else
				return (nums1[(n) / 2 - 1] + nums1[(n) / 2]) / 2.0;
		}
		if (n == 0) {
			if (m % 2)
				return nums2[m / 2];
			else
				return (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
		}
		while (i < (n + m) / 2) {
			if (a < n && b < m) {
				if (nums1[a] > nums2[b]) {
					flag = nums2[b];
					b++;
				}
				else {
					flag = nums1[a];
					a++;
				}
			}
			else if (a == n) {
				flag = max(nums2[b], nums1[n - 1]);
				b++;
			}
			else if (b == m) {
				flag = max(nums1[a], nums2[m - 1]);
				a++;
			}
			i++;
		}
		cout << "a=" << a << " " << "b=" << b << endl;
		if (a < n && b < m) {
			if (nums1[a] > nums2[b]) {
				flag_ = nums2[b];
				b++;
			}
			else {
				flag_ = nums1[a];
				a++;
			}
		}
		else if (a == n) {
			flag_ = max(nums2[b], nums1[n - 1]);
		}
		else if (b == m) {
			flag_ = max(nums1[a], nums2[m - 1]);
		}
		if ((n + m) % 2) {
			return flag_*1.0;
		}
		else
			return (double)(flag_ + flag) / 2.0;

	}
};