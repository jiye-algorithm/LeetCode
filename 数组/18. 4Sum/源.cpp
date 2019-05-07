
/************************************************************************/
/* 2016��7��18��17:15:15
	��ҳ
	
	������ �����ö��ֲ��ң� �����ᳬʱ�� 
	���ÿռ���Ի�ȡʱ���˼·�� ����ת������
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