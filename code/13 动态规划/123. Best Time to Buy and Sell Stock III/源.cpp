#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		if (prices.size() < 2) return 0;

		int n = prices.size();
		vector<int> f(n, 0);
		vector<int> g(n, 0);

		int valley = prices[0];
		for (int i = 1; i < n; ++i)
		{
			valley = min(valley, prices[i]);
			f[i] = max(f[i], prices[i] - valley);
		}

		int peak = prices[n - 1];
		for (int i = n - 2; i >= 0; --i)
		{
			peak = max(peak, prices[i]);
			g[i] = max(g[i + 1], peak - prices[i]);
		}

		int max_profit = 0;
		for (int i = 0; i < n; ++i)
		{
			max_profit = max(max_profit, g[i] + f[i]);
		}

		return max_profit;
	}
};