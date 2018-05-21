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
	int lengthOfLongestSubstring(string s) {
		string::iterator it, it_0;
		int max = 0;
		string result;
		if (s.size() == 0 || s.size() == 1) {
			return s.size();
		}
		for (it = s.begin(); it != s.end(); it++) {
			result = *it;
			for (it_0 = it + 1; it_0 != s.end(); it_0++) {
				if (result.find(*it_0) == string::npos) {
					result.push_back(*it_0);
					if (result.size() > max) {
						max = result.size();
					}
				}
				else {
					//cout<<result<<endl;
					if (result.size() > max) {
						max = result.size();
					}
					break;
				}
			}
		}
		return max;
	}
};

string stringToString(string input) {
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}