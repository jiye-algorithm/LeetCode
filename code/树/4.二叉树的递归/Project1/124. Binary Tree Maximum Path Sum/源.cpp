#include <vector>
#include <stack>

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

		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return root->val;

		return maxPathSum(root, true);
	}
private:
	int maxPathSum(TreeNode* root, bool b) {

		int left = 0;
		int right = 0;

		if (root->left) left = maxPathSum(root->left);
		if (root->right) right = maxPathSum(root->right);

		left = left > 0 ? left : 0;
		right = right > 0 ? right : 0;

		root->val = root->val > 0 ? root->val : 0;

		return root->val + left + right;
	}
};