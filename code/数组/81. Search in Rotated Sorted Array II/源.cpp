#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {

		int first = 0;
		int last = nums.size();

		while (first != last)
		{
			const int mid = (first + last) / 2;

			if (target == nums[mid]) return true;

			if (nums[first] < nums[mid])
			{
				if (target < nums[mid] && nums[first] <= target) last = mid;
				else first = mid + 1;
			}
			else if (nums[first] > nums[mid])
			{
				if (target <= nums[last - 1] && nums[mid] < target) first = mid + 1;
				else  last = mid;
			}
			else
			{
				first++;
			}
		}

		return false;
	}
};