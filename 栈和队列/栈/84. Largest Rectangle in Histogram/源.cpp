#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {

		heights.push_back(0);

		stack<int> s;

		int result = 0;
		for (int i = 0; i < heights.size();)
		{
			if (s.empty() || heights[i] > heights[s.top()])
				s.push(i++);
			else
			{
				int temp = s.top();
				s.pop();

				result = max(result,
					heights[temp] * (s.empty() ? i : i - s.top() - 1));
			}
		}

		return result;

	}
};