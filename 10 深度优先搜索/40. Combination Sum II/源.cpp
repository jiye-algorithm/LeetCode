#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		sort(candidates.begin(), candidates.end());

		vector<int> mid;
		vector<vector<int> > result;
		dfs(candidates, target, 0, mid, result);

		return result;
	}

private:
	void dfs(vector<int>& candicates, int gap, int start, vector<int>& mid, vector<vector<int> >& result)
	{
		if (gap == 0)
		{
			if (find(result.begin(), result.end(), mid) != result.end()) return;
			result.push_back(mid);
			return;
		}

		for (int i = start; i < candicates.size(); ++i)
		{
			if (gap < candicates[i]) return;
			mid.push_back(candicates[i]);
			dfs(candicates, gap - candicates[i], i + 1, mid, result);
			mid.pop_back();
		}
	}
};