#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) 
	{

		this->columns = vector<int>(n, 0);
		this->principal_diagonals = vector<int>(2 * n, 0);
		this->counter_diagonals = vector<int>(2 * n, 0);

		vector<vector<string> > result;
		vector<int> C(n, 0); // C[i] ��ʾ��i �лʺ����ڵ��б��

		dfs(0, C, result);

		return result;
	}

private:

	// �������������ڼ�֦
	vector<int> columns; // ��ʾ�Ѿ����õĻʺ�ռ������Щ��
	vector<int> principal_diagonals; // ռ������Щ���Խ���
	vector<int> counter_diagonals; // ռ������Щ���Խ���

	void dfs(int row, vector<int> &C,	vector<vector<string> > &result) 
	{

		const int N = C.size();

		if (row == N)
		{ 
			// ��ֹ������Ҳ��������������ζ���ҵ���һ�����н�
			vector<string> solution;
			for (int i = 0; i < N; ++i) 
			{
				string s(N, '.');
				for (int j = 0; j < N; ++j)
				{
					if (j == C[i])
					{
						s[j] = 'Q';
						break;
					}
				}
				solution.push_back(s);
			}
			result.push_back(solution);

			return;
		}

		for (int j = 0; j < N; ++j)
		{ 
			// ��չ״̬��һ��һ�е���
			const bool ok = columns[j] == 0 && 
									principal_diagonals[row + j] == 0
									&& counter_diagonals[row - j + N] == 0;
			if (ok)
			{ 
				// ��֦������Ϸ��������ݹ�
				// ִ����չ����
				C[row] = j;
				columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 1;

				dfs(row + 1, C, result);

				// ��������
				// C[row] = 0;
				columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 0; 

			}
		}
	}
};