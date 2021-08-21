#include <vector>
#include <stack>

using namespace  std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {

		vector<int> ans;

		TreeNode* p, *q;

		stack< TreeNode*> s;

		p = root;

		do 
		{
			while (p != nullptr)
			{
				s.push(p);
				p = p->left;
			}

			q = nullptr;

			while (!s.empty())
			{
				p = s.top();
				s.pop();

				if (p->right == q)
				{
					ans.push_back(p->val);
					q = p;
				}
				else
				{
					s.push(p);
					p = p->right;
					break;
				}
			}

		} while (!s.empty());


		return ans;
	}
};