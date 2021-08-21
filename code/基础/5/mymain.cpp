#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int size = s.size();

		if (size == 0) return "";
		if (size == 1) return s;

		int max_len = 1, max_begin = 0;

		for (int i = 0; i < size;)
		{
			if (size - i <= max_len / 2) break;

			int k = i, j = i;
			while (k < size - 1 && s[k] == s[k + 1]) k++;

			i = k + 1;
			while (j > 0 && k < size - 1 && s[k + 1] == s[j - 1]) { ++k; --j; }
			int new_len = k - j + 1;
			if (max_len < new_len) {
				max_len = new_len;
				max_begin = j;
			}
		}

		return s.substr(max_begin, max_len);
	}
};