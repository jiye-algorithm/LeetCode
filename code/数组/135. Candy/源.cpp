#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		
		int n = ratings.size();
		int result = n;
		vector<int> increment(n);

		// ´Ó×óÓÒ¸÷É¨ÃèÒ»±é
		for (int i = 1, inc = 1; i < n; ++i)
			if (ratings[i] > ratings[i - 1])
				increment[i] = max(inc++, increment[i]);
			else
				inc = 1;

		for (int i = n - 2, inc = 1; i >= 0; --i)
			if (ratings[i] > ratings[i + 1])
				increment[i] = max(inc++, increment[i]);
			else
				inc = 1;

		for (int i = 0; i < n; ++i)
			result += increment[i];

		return result;
	}
};