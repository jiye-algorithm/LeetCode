#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace  std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		n = nums.size();

		vector<vector<int> > ans;

		unordered_map<int, int> count_map;
		for_each(nums.begin(), nums.end(), [&count_map](int e){
			if (count_map.find(e) != count_map.end())
				count_map[e] ++;
			else
				count_map[e] = 1;
		});

		vector<pair<int, int> > count_pair;

		for_each(count_map.begin(), count_map.end(), [&count_pair](pair<int, int> e){
			count_pair.push_back(e);
		});

		vector<int> path;
		permuteUnique(count_pair.begin(), count_pair.end(), path, ans);

		return ans;

	}

private:  

	typedef vector<pair<int, int> >::const_iterator Iter;
	size_t n;

	void permuteUnique(Iter begin, Iter end, vector<int>& path, vector<vector<int> >& ans)
	{
		if (path.size() == n)
		{
			ans.push_back(path);
		}

		for (auto i = begin; i != end; ++i)
		{
			int count = 0;
			for (auto j = path.begin(); j != path.end(); ++j)
			{
				if (*j == i->first) count++;
			}

			if (count < i->second)
			{
				path.push_back(i->first);
				permuteUnique(begin, end, path, ans);
				path.pop_back();
			}
		}

	}
};