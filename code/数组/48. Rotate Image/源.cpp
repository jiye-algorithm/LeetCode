/*
	首先沿着副对角线翻转一次，然后沿着水平中线翻转一次。

	通过对折是先旋转效果
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		const int n = matrix.size();

		//  副对角线， 反转
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n - i; ++j)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);

		// 水平对折
		for (int i = 0; i < n / 2; ++i)
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);

	}
};