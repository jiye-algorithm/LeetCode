/*
1. ɨ��һ�飬�ҵ���ߵ����ӣ�������ӽ������Ϊ���룻
2. �������һ�룻
3. �����ұ�һ�롣

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