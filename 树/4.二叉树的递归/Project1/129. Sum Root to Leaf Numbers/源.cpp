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
	int sumNumbers(TreeNode* root) {

		if (root == nullptr) return 0;

		sum = 0;

		son(root, 0);

		return sum;
	}

private:
	int sum;
	void son(TreeNode* root, int num)
	{
		int left = 0;
		int right = 0;

		num = num * 10 + root->val;

		if (root->left == nullptr && root->right == nullptr)
		{
			sum += num;
			return;
		}

		if (root->left)		son(root->left, num);
		if (root->right)		son(root->right, num);

	}
};