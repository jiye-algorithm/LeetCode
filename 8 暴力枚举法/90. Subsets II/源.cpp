#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;

		vector<int> path;

		subsetsWithDup(nums, path, nums.begin(), ans);

		return ans;

	}

private:
	void  subsetsWithDup(vector<int>& nums, vector<int>& path, vector<int>::iterator start, vector<vector<int>>& ans) {

		ans.push_back(path);

		for (auto i = start; i < nums.end(); ++i)
		{
			if (i != start && *i == *(i - 1)) continue;
			path.push_back(*i);
			subsetsWithDup(nums, path, i + 1, ans);
			path.pop_back();
		}

	}
};

int main()
{
	Solution s;
	s.subsetsWithDup(vector<int>({ 1, 2, 2 }));

	return 0;
}