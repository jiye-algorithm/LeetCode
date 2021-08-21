#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> vs;
		vs.resize(numRows);

		int len = s.length();
		int i = 0;
		while (i < len)
		{
			for (int idx = 0; idx < numRows && i < len; ++idx)
				vs[idx].push_back(s[i++]);

			for (int idx = numRows - 2; idx >= 1 && i < len; --idx)
				vs[idx].push_back(s[i++]);
		}

		string zigzags;
		for (string v : vs) zigzags += v;

		return zigzags;
	}
};