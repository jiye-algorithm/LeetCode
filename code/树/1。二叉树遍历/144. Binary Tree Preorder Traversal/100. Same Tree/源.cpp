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
	bool isSameTree(TreeNode* p, TreeNode* q) {

		if (!q && !p) return true;

		if (!q || !p) return false;

		if (p->val == q->val)
		{
			bool left = isSameTree(p->left, q->left);
			bool right = isSameTree(p->right, q->right);

			return left && right;
		}

		return false;
	}
};