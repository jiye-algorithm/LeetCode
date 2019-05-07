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

		return pathSum(root, sum, temp);
	}

private:
	vector<vector<int>> pathSum(TreeNode* root, int sum, vector<int>& vec) {

		vector<vector<int> > ans;

		vec.push_back(root->val);

		if (root->left == nullptr && root->right == nullptr && sum == root->val)
		{
			ans.push_back(vec);
			vec.pop_back();
			return ans;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			vec.pop_back();
			return ans;
		}

		vector<vector<int> > left, right;
		if (root->left)  left = pathSum(root->left, sum - root->val, vec);
		if (root->right) right = pathSum(root->right, sum - root->val, vec);

		for (auto iter = left.begin(); iter != left.end(); ++iter)
		{
			ans.push_back(*iter);
		}

		for (auto iter = right.begin(); iter != right.end(); ++iter)
		{
			ans.push_back(*iter);
		}

		vec.pop_back();

		return ans;
	}
};

