#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {

		int left = 0; 
		int right = height.size() - 1;
		int max_area = INT_MIN;
		while (left < right)
		{
			int area = min(height[left], height[right]) * (right - left);
			max_area = max(max_area, area);
			if (height[left] <= height[right]) left++;
			else right--;
		}

		return max_area;
	}
};