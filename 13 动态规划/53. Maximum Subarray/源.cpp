#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		const int n = nums.size();

		vector<int> f(n, 0);

		int target = INT_MIN;
		for (int i = 1; i < n; ++i)
		{
			f[i] = max(f[i - 1] + nums[i], nums[i]);
			if (f[i] > target) target = f[i];
		}

		return target;
	}
};