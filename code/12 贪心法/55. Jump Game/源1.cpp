
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool canJump(vector<int>& nums) {

		int n = nums.size();
		int reach = 1;

		for (int i = 0; i < reach && reach < n; ++i)
			reach = max(reach, i + 1 + nums[i]);

		return reach >= n;
	}
};
