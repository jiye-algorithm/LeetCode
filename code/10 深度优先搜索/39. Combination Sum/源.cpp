#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		sort(candidates.begin(), candidates.end());
		vector<int> v;
		vector<vector<int> > result;
		dfs(candidates, target, 0, v, result);

		return result;
	}

private:
	void dfs(vector<int>& candidates, int gap,  int start, vector<int>& v, vector<vector<int> >& result) {

		if (gap == 0)
		{
			result.push_back(v);
			return;
		}

		for (int i = start; i < candidates.size(); ++i)
		{
			if (gap < candidates[i]) break;

			v.push_back(candidates[i]);
			dfs(candidates, gap - candidates[i], i, v, result);
			v.pop_back();
		}

	}
};