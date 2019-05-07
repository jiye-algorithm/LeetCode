#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		
		nums.erase(unique(nums.begin(), nums.end()), nums.end());

		
		return nums.size();
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);

	Solution s;
	s.removeDuplicates(nums);

	return 0;
}