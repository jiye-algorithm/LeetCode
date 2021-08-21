
/************************************************************************/
/* 2016年7月18日17:15:15
	吉页
	
	先排序 再利用二分查找， 这样会超时， 
	利用空间可以换取时间的思路， 可以转换策略
*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;

		if (nums.size() < 4) return result;

		sort(nums.begin(), nums.end());

		auto last = nums.end();
		for (auto a = nums.begin(); a < prev(last, 3); a = upper_bound(a, prev(last, 3), *a))
		{
			for (auto b = next(a); b < prev(last, 2); b = upper_bound(b, prev(last, 2), *b))
			{
				for (auto c = next(b); c < prev(last); c = upper_bound(c, prev(last), *c))
				{
					int d = target - *c - *b - *a;

					if (binary_search(next(c), last, d))
					{
						result.push_back(vector < int > {*a, *b, *c, d});
					}
				}
			}
		}

		return result;
	}
};