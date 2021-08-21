#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {

		int index = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != val)
				nums[index++] = nums[i];
		}

		return index;
	}

};