#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {

		if (p[0] == '*')
		{
			int i = 0;
			while (p[i] == '*') ++i;
			p = p.substr(i);

			if (p.empty()) return true;
			while (!s.empty() && !isMatch(s, p))
			{
				s = s.substr(1);
			}
			return !s.empty();
		}
		else if (p.empty() || s.empty()) return s.size() == p.size();
		else if (p[0] == s[0] || p[0] == '?') return isMatch(s.substr(1), p.substr(1));
		else return false;
	}
};