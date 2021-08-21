#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {

		if (root == nullptr) return true;

		if (root->left && root->val <= getMax(root->left)) return false;
		if (root->right && root->val >= getMin(root->right)) return false;
		

		return isValidBST(root->left) && isValidBST(root->right);

	}

private:
	// 返回以此节点 为根的 最大值
	int getMax(TreeNode* root)
	{
		int max = root->val;

		if (root->left && root->left->val > max)
			max = root->left->val;

		if (root->right && root->right->val > max)
			max = root->right->val;

		if (root->left)
		{
			int temp = getMax(root->left);
			max = temp > max ? temp : max;
		}

		if (root->right)
		{
			int temp = getMax(root->right);
			max = temp > max ? temp : max;
		}

		return max;
	}

	int getMin(TreeNode* root)
	{
		int min = root->val;

		if (root->left && root->left->val < min)
			min = root->left->val;

		if (root->right && root->right->val < min)
			min = root->right->val;

		if (root->left)
		{
			int temp = getMax(root->left);
			min = temp < min ? temp : min;
		}

		if (root->right)
		{
			int temp = getMax(root->right);
			min = temp < min ? temp : min;
		}

		return min;
	}
};