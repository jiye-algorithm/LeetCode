
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		int total = n + m;

		if (total & 0x1)
			return find_kth(nums1, m, nums2, n, total / 2 - 1);
		else
			return (find_kth(nums1, m, nums2, n, total / 2) +
			find_kth(nums1, m, nums2, n, total / 2 - 1)) / 2;
	}

private:
	static double find_kth(vector<int> A, int m, vector<int> B, int n, int k) {

		if (m > n) return find_kth(B, n, A, m, k);
		if (m == 0) return B[k - 1];
		if (k == 1) return min(A[0], B[0]);

		int pa = min(k / 2, m), pb = k - pa;

		if (A[pa - 1] < B[pb - 1])
			return find_kth(A + pa, m - pa, B, n, k - pa);
		else if (A[pa - 1] > B[pb - 1])
			return find_kth(A, m, B + pb, n - pb, k - pb);
		else
			return A[pa - 1];
	}
};
