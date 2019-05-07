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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {

		vector<vector<int> > ans;

		if (root == nullptr) return ans;

		vector<int> temp;
		stack<TreeNode*> s;

		int sum2 = sum;
		s.push(root);
		while (!s.empty())
		{
			root = s.top(); 

			if (root->right) s.push(root->right);
			if (root->left) s.push(root->left);

			sum -= root->val;
			temp.push_back(root->val);
			if (root->left == nullptr && root->right == nullptr && sum == 0)
			{
				ans.push_back(temp);
				sum += root->val;
				temp.pop_back();
				continue;
			}

			if (root->left == nullptr && root->right == nullptr)
			{
				sum += root->val;
				temp.pop_back();
				continue;
			}

		}

		return ans;
	}
};

int main()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* rootLeft = new TreeNode(4);
	TreeNode* rootRight = new TreeNode(8);

	root->left = rootLeft;
	root->right = rootRight;

	rootLeft->left = new TreeNode(11);
	TreeNode* temp = rootLeft->left;

	temp->left = new TreeNode(7);
	temp->right = new TreeNode(2);

	rootRight->left = new TreeNode(13);
	rootRight->right = new TreeNode(4);

	temp = rootRight->right;
	temp->left = new TreeNode(5);
	temp->right = new TreeNode(1);

	Solution s;
	s.pathSum(root, 22);

	return 0;

}

