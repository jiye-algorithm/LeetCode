#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {

		int step = 0;
		int left = 0;
		int right = 0;

		if (nums.size() == 1) return step;

		while (left <= right)
		{
			step++;
			const int old_right = right;
			for (int i = left; i <= old_right; ++i)
			{
				int new_right = i + nums[i];
				if (new_right >= nums.size() - 1) return step;
				if (new_right > right) right = new_right;
			}

			left = old_right + 1;
		}
		
		return 0;
	}
};