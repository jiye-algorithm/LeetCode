/*
1. 扫描一遍，找到最高的柱子，这个柱子将数组分为两半；
2. 处理左边一半；
3. 处理右边一半。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;


class Solution {
public:
	int trap(vector<int>& height) {

		int n = height.size();
		int max = 0;

		for (int i = 0; i < n; ++i)
			if (height[i] > height[max]) max = i;

		int sum = 0;
		for (int i = 0, peak = 0; i < max; ++i)
		{
			if (height[i] > peak) peak = height[i];
			else sum += peak - height[i];
		}

		for (int i = n - 1, top = 0; i > max; --i)
			if (height[i] > top) top = height[i];
			else sum += top - height[i];

		return sum;
	}
};