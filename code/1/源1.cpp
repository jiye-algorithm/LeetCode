#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> vec;

		int m = nums1.size();
		for (int i = 0; i < m; ++i)
		{
			vec.push_back(nums1[i]);
		}

		int n = nums2.size();
		for (int i = 0; i < n; ++i)
		{
			vec.push_back(nums2[i]);
		}

		sort(vec.begin(), vec.end());

		int a = (vec.size()) / 2;
		if (vec.size() % 2 == 0)
		{
			return (vec[a] + vec[a - 1]) / 2.0;
		}
		else
		{
			return vec[a] / 1.0;
		}

	}
};

int main()
{
	vector<int> v;
	vector<int> v2;
	v.push_back(3);
	v.push_back(4);

	Solution s;
	double d =  s.findMedianSortedArrays(v, v2);

	cout << d;

	return 0;
}