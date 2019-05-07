#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		vector<vector<int> > ans;

		if (root == nullptr) return ans;

		bool tag = false;

		queue<TreeNode*> cur, next;
		cur.push(root);

		vector<int> level;
		while (!cur.empty())
		{
			while (!cur.empty())
			{
				root = cur.front(); cur.pop();
				level.push_back(root->val);

				if (root->left != nullptr) next.push(root->left);
				if (root->right != nullptr) next.push(root->right);
			}

			if (tag)  reverse(level.begin(), level.end());

			ans.push_back(level);
			tag = !tag;
			level.clear();
			swap(cur, next);
		}

		return ans;
	}
};