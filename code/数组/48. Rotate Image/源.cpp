/*
	�������Ÿ��Խ��߷�תһ�Σ�Ȼ������ˮƽ���߷�תһ�Ρ�

	ͨ������������תЧ��
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		const int n = matrix.size();

		//  ���Խ��ߣ� ��ת
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n - i; ++j)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);

		// ˮƽ����
		for (int i = 0; i < n / 2; ++i)
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);

	}
};