
//  ��򣬲����ܴ������ε������ֻҪ����ż���Σ����������㡣

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

