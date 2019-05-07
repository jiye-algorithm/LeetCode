#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		
		int n = nums.size();

		sort(nums.begin(), nums.end());

		int result = nums[0];

		int i;
		for ( i = 0; i < n - 1; i += 2)
		{
			if (nums[i] != nums[i + 1])
			{
				result = nums[i];
				break;
			}
		}

		if (i == n - 1)
			result = nums[n - 1];

		return result;

	}
};

int main()
{
	Solution s;
	vector<int> vec({ 1, 3, 1, -1, 3 });

	int result = s.singleNumber(vec);


	cout << endl;

	return 0;
}