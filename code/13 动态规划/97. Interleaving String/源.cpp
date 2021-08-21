#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {

		if (s3.size() != s1.size() + s2.size()) return false;

		vector<vector<bool>> f(s1.size() + 1, vector<bool>(s2.size() + 1, true));

		for (int i = 1; i <= s1.size(); ++i)
			f[i][0] = s1[i - 1] == s3[i - 1] && f[i - 1][0];

		for (int j = 1; j <= s2.size(); ++j)
			f[0][j] = f[0][j - 1] && s2[j - 1] == s3[j - 1];
		                     
		for (int i = 1; i <= s1.size(); ++i)
		{
			for (int j = 1; j <= s2.size(); ++j)
			{
				f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
			}
		}

		return f[s1.size()][s2.size()];
	}
};

int main()
{
	Solution s;
	s.isInterleave("a", "b", "ab");

	return 0;
}