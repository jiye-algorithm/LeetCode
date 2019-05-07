#include <vector>
#include <queue>
#include <algorithm>

using namespace  std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>> ans;

		if (root == nullptr) return ans;

		queue<TreeNode*> cur, next;

		vector<int> level;

		cur.push(root);

		while (!cur.empty())
		{
			while (!cur.empty())
			{
				root = cur.front();
				cur.pop();

				level.push_back(root->val);

				if (root->left != nullptr) next.push(root->left);
				if (root->right != nullptr) next.push(root->right);
			}

			ans.push_back(level);
			level.clear();
			swap(cur, next);
		}

		return ans;
	}
};


