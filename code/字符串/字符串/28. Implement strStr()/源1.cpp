// 唉， 答案暴力的方案都知道减点东西， 我太弱了

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {

		if (needle.size() == 0) return 0;

		int p1, p2;
		int p1_advance = 0;
		for (p1 = 1; p1 < needle.size(); ++p1)
			p1_advance++;

		for (p1 = 0; p1_advance < haystack.size(); ++p1_advance)
		{
			int p1_old = p1;
			p2 = 0;
			while (p2 < needle.size() && p1 < haystack.size() && haystack[p1] == needle[p2])
			{
				++p1;
				++p2;
			}

			if (p2 == needle.size()) return p1_old;

			p1 = p1_old + 1;
		}

		return -1;
	}
};

int main()
{
	Solution s;
	s.strStr("mississippi",	"issi");

	return 0;
}