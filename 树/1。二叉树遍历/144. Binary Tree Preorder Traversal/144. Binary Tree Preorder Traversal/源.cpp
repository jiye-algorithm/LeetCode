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
	vector<int> preorderTraversal(TreeNode* root) {
		
		vector<int> ans;

		const TreeNode* p = root;
		stack<const TreeNode *> s;

		if (p != nullptr) s.push(p);

		while (!s.empty())
		{
			p = s.top(); s.pop();
			if (p->right != nullptr) s.push(p->right);
			if (p->left != nullptr) s.push(p->left);

			ans.push_back(p->val);
		}

		return ans;
	}
};