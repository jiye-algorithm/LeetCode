#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		if (obstacleGrid.empty()) return 0;

		int rows = obstacleGrid.size();
		int cols = obstacleGrid[0].size();

		if (rows == 0 || cols == 0) return 0;

		this->path = vector<vector<int> >(rows + 1, vector<int>(cols + 1, 0));

		return uniquePathsWithObstacles(obstacleGrid, rows, cols);
	}

private:
	vector<vector<int> > path;

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int m, int n) {

		if (m < 1 || n < 1) return 0;

		if (m == 1 && n == 1) return 1;

		if (obstacleGrid[m - 1][n - 1] == 1) return 0;

		if (path[m][n])
		{
			return path[m][n];
		}

		return getOrUpdate(obstacleGrid, m - 1, n) + getOrUpdate(obstacleGrid, m, n - 1);
	}

	int getOrUpdate(vector<vector<int>>& obstacleGrid, int m, int n)
	{
		if (path[m][n] != 0) return path[m][n];

		path[m][n] = uniquePathsWithObstacles(obstacleGrid, m, n);

		return path[m][n];
	}

};