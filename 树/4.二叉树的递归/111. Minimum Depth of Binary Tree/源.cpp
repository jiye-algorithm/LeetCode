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
	int minDepth(TreeNode* root) {

		if (root == nullptr) return 0;

		if (root->left == nullptr) return minDepth(root->right) + 1;

		if (root->right == nullptr) return minDepth(root->left) + 1;

		int left = minDepth(root->left);
		int right = minDepth(root->right);

		return left > right ? right + 1 : left + 1;
		
	}
};