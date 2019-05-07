#include <vector>
#include <algorithm>

using namespace  std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		return searchRange(nums, target, 0, nums.size());

	}

private:
	vector<int> searchRange(vector<int>& nums, int target, int begin, int end) {

		if (begin == end) return vector < int >({ -1, -1 });

		int mid = (begin + end) / 2;

		if (target < nums[mid]) return searchRange(nums, target, begin, mid);
		else if (target > nums[mid]) return searchRange(nums, target, mid + 1, end);
		else
		{
			int temp = mid;
			while (--temp >= begin && nums[temp] == target);
			while (++mid < end && nums[mid] == target);
			return vector<int>({ temp + 1, mid - 1 });
		}


	}
};