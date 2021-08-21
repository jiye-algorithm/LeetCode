#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int rowLen = matrix.size();
		int colLen = (matrix[rowLen - 1]).size();

		int row = searchMatrix(matrix, target, 0, rowLen);
		if (row == -1) return false;

		int col = searchMatrix(matrix[row], target, 0, colLen);
		if (col == -1) return false;

		return true;

	}

private:
	int searchMatrix(vector<vector<int>>& matrix, int target, int begin, int end) {

		if (begin == end) return begin - 1;

		int mid = (begin + end) / 2;
		if (target < matrix[mid][0]) return searchMatrix(matrix, target, begin, mid);
		else if (target == matrix[mid][0]) return mid;
		else
			return searchMatrix(matrix, target, mid + 1, end);

	}

private:
	int searchMatrix(vector<int>& matrix, int target, int begin, int end) {
	
		if (begin == end)
			return -1;

		int mid = (begin + end) / 2;
		if (target < matrix[mid]) return searchMatrix(matrix, target, begin, mid);
		else if (target == matrix[mid]) return mid;
		else
			return searchMatrix(matrix, target, mid + 1, end);

	}
};

int main()
{

	Solution s;
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	vector<vector<int> > aa;
	aa.push_back(a);
	s.searchMatrix(aa, 3);

	return 0;
}