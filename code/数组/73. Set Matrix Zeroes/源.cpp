#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		size_t n = matrix.size();
		size_t m = matrix[0].size();

		vector<bool> rows(n, false);
		vector<bool> cols(m, false);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++m)
				if (matrix[i][j] == 0)
					rows[i] = cols[j] = true;

		for (int i = 0; i < n; ++i)
			if (rows[i] == true)
				fill(matrix[i].begin(), matrix[i].end(), 0);

		for (int j = 0; j < m; ++j)
			if (cols[j] == true)
				for (int i = 0; i < n; ++i)
					matrix[i][j] = 0;

	}
};