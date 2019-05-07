#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {

		max_sum = INT_MIN;

		dfs(root);

		return max_sum;
	}
private:
	int max_sum;

	int dfs(const TreeNode* root) {

		if (root == nullptr) return 0;

		int sum = root->val;

		int left = 0; 
		int right = 0;

		if (root->left) left = dfs(root->left);
		if (root->right) right = dfs(root->right);

		if (left > 0) sum += left;
		if (right > 0)  sum += right;

		max_sum = max(max_sum, sum);

		return max(left, right) > 0 ? max(left, right) + root->val : root->val;
	}
};