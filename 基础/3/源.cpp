#include <iostream>
#include <string>

using namespace  std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int hash[200];
		for (int i = 0; i < 200; ++i)
			hash[i] = 0;

		string ans = "";
		int size = s.size();

		for (int i = 0; i < size; ++i)
		{
			for (int i = 0; i < 200; ++i)
				hash[i] = 0;

			string temp = "";
			temp += s[i];
			hash[s[i] - 0] ++;
			for (int j = i + 1; j < size; ++j)
			{
				hash[s[j] - 0] ++;
				if (hash[s[j] - 0] == 2)
				{
					break;
				}			

				temp += s[j];
			}

			if (ans.length() < temp.length())
				ans = temp; 
		}
		return ans.size();
	}
};