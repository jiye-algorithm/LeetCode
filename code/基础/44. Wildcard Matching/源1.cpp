#include <iostream>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		string ss = s;
		string star = "";

		while (!s.empty())
		{
			if (s[0] == p[0] || '?' == p[0])
			{
				s = s.substr(1);
				p = p.substr(1);
			}

			if (p[0] == '*')
			{
				ss = s;
				star = p[0]
			}
		}
	}
};