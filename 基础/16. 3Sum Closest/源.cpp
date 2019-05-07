
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		int result = 0;

		if (nums.size() < 3) return result;

		int min_gap = INT_MAX;
		sort(nums.begin(), nums.end());

		for (auto a = nums.begin(); a < prev(nums.end(), 2); a = upper_bound(a, prev(nums.end(), 2), *a))
		{
			auto b = next(a);
			auto c = prev(nums.end());

			while (b < c)
			{
				 int sum = *a + *b + *c;
				const int gap = abs(target - sum);

				if (gap < min_gap)
				{
					min_gap = gap;
					result = sum;
				}

				if (sum < target) ++b;
				else  --c;
			}
		}

		return result;
	}
};	