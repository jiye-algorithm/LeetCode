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
	TreeNode* sortedArrayToBST(vector<int>& nums) {

		TreeNode* root = nullptr;

		for (int i = 0; i < nums.size(); ++i)
		{
			root = insert(root, nums[i]);
		}

		return root;
	}

private:
	int height(TreeNode* root)
	{
		if (root == nullptr) return 0;

		int left = height(root->left);
		int right = height(root->right);

		return left > right ? left + 1 : right + 1;
	}

	TreeNode* insert(TreeNode* root, int val)
	{
		if (root == nullptr)
			return new TreeNode(val);

		if (root->val > val)
			root->left = insert(root->left, val);
		else 
			root->right = insert(root->right, val);

		adjust(root);

		return root;
	}

	TreeNode* adjust(TreeNode* root)
	{

		if (root == nullptr) return root;

		while (abs(height(root->left) - height(root->right)) > 1)
		{
			TreeNode* right = root->right;
			TreeNode* left = root->left;

			if (left)
			{
				left->right = right->left;
				right->left = root;
			}
			else
			{
				right->left = left;
			}
			root = right;
		}

		return root;
	}

};

int main()
{
	Solution s;
	s.sortedArrayToBST(vector < int > {3, 5, 8});

	return 0;
}