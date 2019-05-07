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
	vector<int> inorderTraversal(TreeNode* root) {

		vector<int> ans;

		const TreeNode* p = root;

		stack<const TreeNode*> s;

		while (!s.empty() || p != nullptr)
		{
			if (p != nullptr)
			{
				s.push(p);
				p = p->left;
			}
			else
			{
				p = s.top();
				s.pop();
				ans.push_back(p->val);
				p = p->right;
			}
			
		}

		return ans;
	}
};