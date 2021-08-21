#include <vector>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {

		if (n == 0) return 0;

		vector<int> C(n, 0);
		this->columns = vector<int>(n, 0);
		this->counter_diagonals = vector<int>(2 * n, 0);
		this->principal_diagonals = vector<int>(2 * n, 0);

		int len = 0;
		dfs(0, C, len);

		return len;

	}

private:
	vector<int> columns, principal_diagonals, counter_diagonals;

	void dfs(int row, vector<int>& C, int& len)
	{
		const int N = C.size();
		if (row == N)
		{
			len++;
			return;
		}

		for (int j = 0; j < N; ++j)
		{
			const bool ok = columns[j] == 0
				&& principal_diagonals[row + j] == 0
				&& counter_diagonals[row - j + N] == 0;

			if (ok)
			{
				C[row] = j;
				columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 1;

				dfs(row + 1, C, len);

				columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 0;
				C[row] = 0;
			}

		}

	}
};