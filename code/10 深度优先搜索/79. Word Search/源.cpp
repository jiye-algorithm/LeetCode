#include <vector>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {

		this->rows = board.size();
		this->cols = board[0].size();

		bool found = false;

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				dfs(board, i, j, word, found);
				if (found) break;
			}
		}

		return found;
	}

private:

	int rows, cols;

	void dfs(vector<vector<char> >& board, int i, int j, string word, bool& found)
	{
		if (found) return;

		if (word.empty())
		{
			found = true;
			return;
		}

		if (i > rows - 1) return;
		if (i < 0) return;
		if (j > cols - 1) return;
		if (j < 0) return;

		if (board[i][j] == '*') return;

		if (board[i][j] == word[0])
		{
			board[i][j] = '*';
		}
		else
		{
			return;
		}

		dfs(board, i + 1, j, word.substr(1), found);
		dfs(board, i - 1, j, word.substr(1), found);
		dfs(board, i, j + 1, word.substr(1), found);
		dfs(board, i, j - 1, word.substr(1), found);

		board[i][j] = word[0];

		return;
	}
};


int main()
{
	vector<vector<char>> board;
	string str = "ABCE";
	vector<char> v(str.begin(), str.end());
	str = "SFCS";
	vector<char> v1(str.begin(), str.end());
	str = "ADEE";
	vector<char> v2(str.begin(), str.end());

	board.push_back(v);
	board.push_back(v1);
	board.push_back(v2);

	Solution s;
	s.exist(board, "ABCCED");

	return 0;
}