#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {

		vector<vector<string> > result;
		if (n == 0) return result;

		vector<int> C(n, 0);
		this->columns = vector<int>(n, 0);
		this->counter_diagonals = vector<int>(2 * n, 0);
		this->principal_diagonals = vector<int>(2 * n, 0);

		dfs(0, C, result);

		return result;
	}

private:
	vector<int> columns, principal_diagonals, counter_diagonals;

	void dfs( int row, vector<int>& C, vector<vector<string> >& result)
	{
		const int N = C.size();
		if (row == N)
		{
			vector<string> solution;
			for (int i = 0; i < N; ++i)
			{
				string s(N, '.');
				s[C[i]] = 'Q';
				solution.push_back(s);
			}
			result.push_back(solution);
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

				dfs(row + 1, C, result);

				columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 0;
				C[row] = 0;
			}

		}

	}

};

int main()
{
	Solution s;
	s.solveNQueens(4);

	return 0;
}