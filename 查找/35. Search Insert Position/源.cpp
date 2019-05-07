#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		return searchInsert(nums, target, 0, nums.size());

	}

private:
	int searchInsert(vector<int>& nums, int target, int begin, int end) {

		if (begin == end) return begin;

		int mid = (begin + end) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) return searchInsert(nums, target, mid + 1, end);
		else return searchInsert(nums, target, begin, mid);

	}
};