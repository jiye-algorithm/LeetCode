/*

1. 从左往右扫描一遍，对于每个柱子，求取左边最大值；
2. 从右往左扫描一遍，对于每个柱子，求最大右值；
3. 再扫描一遍，把每个柱子的面积并累加。

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;


class Solution {
public:
	int trap(vector<int>& height) {

		int n = height.size();

		vector<int> max_left(n);
		vector<int> max_right(n);

		for (int i = 1; i < n; ++i)
		{
			max_left[i] = max(max_left[i - 1], height[i - 1]);
			max_right[n - i - 1] = max(max_right[n - i], height[n - i]);
		}

		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int m = min(max_left[i], max_right[i]);
			if (m > height[i])
				sum += m - height[i];
		}

		return sum;

	}
};