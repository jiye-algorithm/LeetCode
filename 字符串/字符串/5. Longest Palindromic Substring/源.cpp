#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

		int n = s.size();

		if (n == 0) return "";

		string longest = s.substr(0, 1);

		int beg = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			string p1 = expandAroundCenter(s, i, i);
			if (p1.size() > longest.size())
			{
				longest = p1;
				beg = i;
			}

			string p2 = expandAroundCenter(s, i, i + 1);
			if (longest.size() < p2.size())
			{
				longest = p2;
				beg = i;
			}
		}

		return longest;
	}

private:
	string expandAroundCenter(string s, int c1, int c2)
	{
		int left = c1, right = c2;
		int n = s.size();
		while (left >= 0 && right < n && s[left] == s[right])
		{
			left--;
			right++;
		}

		return s.substr(left + 1, right - left - 1);
	}
};