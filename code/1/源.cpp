
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		ans.resize(2);
		int size = nums.size();
		for (int i = 0; i < size; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					ans[0] = i;
					ans[1] = j;
					break;
				}
			}
		}

		return ans;
	}
};