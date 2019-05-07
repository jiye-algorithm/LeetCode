#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {

		buck_sort(nums);
		
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != i + 1) return i + 1;
		}

		return nums.size() - 1;
	}
	
private:
	void buck_sort(vector<int>& nums)
	{
		int len = nums.size();

		for (int i = 0; i < len; ++i)
		{
			while (nums[i] != i + 1)
			{
				if (nums[i] > len || nums[i] < 1 || nums[i] == nums[nums[i] - 1]) break;
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
	}
};