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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {

		vector<vector<int> > ans;

		if (root == nullptr) return ans;

		queue<TreeNode*> q, p;

		q.push(root);
		vector<int> level;
		while (!q.empty())
		{
			while (!q.empty())
			{
				root = q.front(); q.pop();

				level.push_back(root->val);

				if (root->left != nullptr) p.push(root->left);
				if (root->right != nullptr) p.push(root->right);
			}

			ans.push_back(level);
			level.clear();

			swap(p, q);
		}


		reverse(ans.begin(), ans.end());

		return ans;
	}
};