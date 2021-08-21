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
	bool isBalanced(TreeNode* root) {

		if (root == nullptr) return true;

		if (!isBalanced(root->left) || !isBalanced(root->right)) return false;

		int left = depthOfTree(root->left);
		int right = depthOfTree(root->right);

		return abs(left - right) < 2;

	}

private:
	int depthOfTree(TreeNode* root)
	{
		if (root == nullptr) return 0;

		int left = depthOfTree(root->left);
		int right = depthOfTree(root->right);

		return max(left, right) + 1;

	}
};