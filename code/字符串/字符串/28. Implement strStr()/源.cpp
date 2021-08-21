#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {

		if (haystack.size() < needle.size()) return -1;

		int index = 0;
		int i = 0;
		for ( i = 0; i < haystack.size(); ++i)
		{
			for (index = 0; index < needle.size(); ++index)
			{
				if (needle[index] != haystack[i + index]) break;
			}

			if (index == needle.size()) break;
		}

		if (index == needle.size()) return  i;
		else
			return -1;

	}
};