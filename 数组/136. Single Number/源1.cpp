
//  异或，不仅能处理两次的情况，只要出现偶数次，都可以清零。

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int n = nums.size();

		int x = nums[0];

		for (int i = 1; i < n; ++i)
			x ^= nums[i];

		return x;

	}
};

