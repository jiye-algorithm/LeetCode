#include <vector>
#include <algorithm>
#include <function>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int> > ans;
		vector<int> path;

		next_permute(nums, path, ans);

		return ans;
	}

private:
	void next_permute(vector<int>& nums, vector<int>& path, vector<vector<int> >& ans)
	{
		if (path.size() == nums.size())
		{
			ans.push_back(path);
			return;
		}

		for (auto i : nums)
		{
			auto pos = find(path.begin(), path.end(), i);

			if (pos == path.end())
			{
				path.push_back(i);
				next_permute(nums, path, ans);
				path.pop_back();
			}
		}
	}
};