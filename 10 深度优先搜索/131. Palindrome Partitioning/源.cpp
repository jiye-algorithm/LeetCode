#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {

		 n = s.size();
		vector<string> path;
		vector<vector<string> > ans;

		partition(s, path, 0, 1, ans);

		return ans;
	}

private:

	int n;

	void partition(string s, vector<string>& path, int prev,  int start, vector<vector<string> >& ans) {

		if (start == n)
		{
			if (isPalindrome(s.substr(prev, start - prev)))
			{
				path.push_back(s.substr(prev, start - prev));
				ans.push_back(path);
				path.pop_back();
			}
			return;
		}

		partition(s, path, prev, start + 1, ans);

		if (isPalindrome(s.substr(prev, start - prev)))
		{
			path.push_back(s.substr(prev, start - prev));
			partition(s, path, start, start + 1, ans);
			path.pop_back();
		}

		return;
	}

	bool isPalindrome(string s)
	{
		string str(s);
		reverse(str.begin(), str.end());

		int i;
		for ( i = 0; i < s.size(); ++i)
		{
			if (str[i] != s[i]) break;
		}

		if (i != s.size()) return false;

		return true;
	}
};

int main()
{
	Solution s;
	s.partition("aab");

	return 0;
}