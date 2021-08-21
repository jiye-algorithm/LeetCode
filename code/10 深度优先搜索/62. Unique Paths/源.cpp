#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {

		this->f = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));

		return dfs(m, n);
	}

private:

	vector<vector<int> > f;
	int dfs(int x, int y ) {

		if (x < 1 || y < 1) return 0;

		if (x == 1 && y == 1) return 1;

		return getOrUpdate(x - 1, y) + getOrUpdate(x, y - 1);
	}

	int getOrUpdate(int x, int y)
	{
		if (f[x][y] > 0) return f[x][y];
		else return f[x][y] = dfs(x, y);
	}
};