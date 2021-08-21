#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		
		const int n = nums.size();

		map<int, int> ans;

		for (int i = 0; i < n; ++i)
		{
			ans[nums[i]] ++;
		}

		int result = 0;
		for (auto iter = ans.begin(); iter != ans.end(); ++iter)
			if (iter->second == 1)
			{
				result = iter->first;
				break;
			}
			
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> vec({ -2, -2, 1, 1, -3, 1, -3, -3, -4, -2 });

	s.singleNumber(vec);

	cout << endl;

	return 0;
}