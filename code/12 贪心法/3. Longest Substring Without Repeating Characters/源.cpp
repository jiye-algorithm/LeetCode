#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		map<char, int> dict;
		int maxLen = 0;
		for (int i = 0, j = 0; i < s.size(); ++i)
		{
			if (dict.find(s[i]) != dict.end())
			{
				j = max(j, dict[s[i]] + 1);
			}
			dict[s[i]] = i;
			maxLen = max(maxLen, i - j + 1);
		}

		return maxLen;
	}
};


int main()
{
	Solution s;
	s.lengthOfLongestSubstring("abcabcbb");

	return 0;
}
