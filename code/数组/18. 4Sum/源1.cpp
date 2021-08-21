
/************************************************************************/
/* 
	第一种代码采用直接遍历的方式， 结果使得时间超过了

	下面的代码利用的思路
		* 利用空间换取了部分时间
		* 降低了时间的成本
	
	代码所涉及到的思想
		* 利用 map 缓存结构， 而且利用的 map  的 key -》value 功能， 成功将结果保存为 key ， 方便了之后向量的操作
		* 利用 set 的查重功能， 实现了查重， 效果

*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		if (nums.size() < 4) return 	vector<vector<int> >();
		sort(nums.begin(), nums.end());

		map<int, vector<pair<int, int>  > > cache;
		// 先将前两个数据保存缓存起来， 利用 map 构造的类数组数据结构， 方便与向量接轨
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				cache[nums[i] + nums[j]].push_back(pair < int, int > (i, j));
			}
		}

		set<vector<int> > result;
		// 判断提取后两个数字
		for (int a = 2; a < nums.size(); ++a)
		{
			for (int b = a + 1; b < nums.size(); ++b)
			{
				const int key = target - nums[a] - nums[b];
				if (cache.find(key) != cache.end())
				{
					for (int c = 0; c < cache[key].size(); ++c)
					{
						if (a <= cache[key][c].second) continue;

						result.insert(vector < int > {nums[cache[key][c].first], nums[cache[key][c].second], nums[a], nums[b]});
					}
				}
			}
		}

		return vector<vector<int> >(result.begin(), result.end());
	}
};