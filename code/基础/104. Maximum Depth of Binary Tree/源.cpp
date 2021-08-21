
#include <iostream>

using namespace std;

struct TreeNode {
     int val;
	TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		
		if (root == NULL) return 0;

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

		int h = left < right ? right : left;

		return h + 1;
	}
};

int main()
{
	TreeNode root(0);
	Solution s;

	int h = s.maxDepth(&root);

	cout << endl;

	return 0;
	
}