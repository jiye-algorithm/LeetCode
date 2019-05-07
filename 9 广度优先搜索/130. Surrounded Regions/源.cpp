#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		
		if (board.size() == 0) return;

		int m = board.size();
		int n = board[0].size();

		for (int i = 0; i < n; ++i)
		{
			bfs(board, 0, i);
			bfs(board, m - 1, i);
		}

		for (int j = 0; j < m; ++j)
		{
			bfs(board, j, 0);
			bfs(board, j, n - 1);
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '+') board[i][j] = 'O';
			}
		}

	}

private:
	void bfs(vector<vector<char>>& board, int i, int j)
	{
		queue<int> q;
		visit(board, i, j, q);

		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			int x = cur / board[0].size();
			int y = cur % board[0].size();

			visit(board, x + 1, y, q);
			visit(board, x - 1, y, q);
			visit(board, x, y - 1, q);
			visit(board, x, y + 1, q);
		}

	}

	void visit(vector<vector<char>>& board, int i, int j, queue<int>& q)
	{
		int m = board.size();
		int n = board[0].size();

		if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

		board[i][j] = '+';
		q.push(i *n + j);
	}
};