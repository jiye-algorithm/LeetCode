#include <vector>
#include <algorithm>

using namespace  std;
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {

		vector<vector<int> > ans;
		vector<int> path;

		combine(n, k, ans, path, 1);

		return ans;
	}

private:
	void combine(int n, int k, vector<vector<int> >& ans, vector<int>& path, int start)
	{
		if (path.size() == k)
		{
			ans.push_back(path);
			return;
		}

		for (int i = start; i < n + 1; ++i)
		{
			path.push_back(i);
			combine(n, k, ans, path, i + 1);
			path.pop_back();
		}
	}
};