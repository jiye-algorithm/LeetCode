#include <iostream>
#include <string>
#include <algorithm>

using namespace  std;

class Solution {
public:
	bool isPalindrome(string s) {

		int size = s.size();

		if (size == 0) return true;

		// 重新组合字符串
		string newStr = "";
		for (int i = 0; i < size; ++i)
		{
			if (isalnum(s[i]))
			{
				newStr += tolower(s[i]);
			}
		}

		size = newStr.size();
		if (size == 0) return true;
		if (1 == size && isalnum(newStr[0])) return true;

		// 判断是不是  
		int left = 0, right = size - 1;
		while (left < right)
		{
			if (newStr[left] != newStr[right])
				break;

			left++;
			right--;
		}
		// 对结果处理
		if (left >= right)  return true;
		else
			return false;
	}
};