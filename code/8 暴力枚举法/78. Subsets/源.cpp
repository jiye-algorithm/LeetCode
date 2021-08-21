#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<vector<int> > ans;
		vector<int> path;

		sort(nums.begin(), nums.end());

		subsets(nums, path, 0, ans);

		return ans;
	}

private:
	void subsets(vector<int>& nums, vector<int>& path, int step, vector<vector<int>>& ans) {

		if (step == nums.size())
		{
			ans.push_back(path);
			return;
		}

		subsets(nums, path, step + 1, ans);
		path.push_back(nums[step]);
		subsets(nums, path, step + 1, ans);
		path.pop_back();

	}
};
