#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		if (n < 2) return 0;

		int cur_min = prices[0];
		int profit = 0;

		for (int i = 1; i < n; ++i)
		{
			profit = max(profit, prices[i] - cur_min);
			cur_min = min(cur_min, prices[i]);
		}

		return profit;
	}
};