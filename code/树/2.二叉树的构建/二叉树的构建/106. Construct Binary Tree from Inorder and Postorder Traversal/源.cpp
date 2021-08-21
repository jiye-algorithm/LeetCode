#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		reverse(postorder.begin(), postorder.end());

		return buildTree(begin(postorder), end(postorder), begin(inorder), end(inorder));

	}

private:
	template<typename InputInterator>
	TreeNode* buildTree(InputInterator pre_first, InputInterator pre_last, InputInterator in_first, InputInterator in_last)
	{

		if (in_first == in_last) return NULL;
		if (pre_last == pre_first) return NULL;

		TreeNode* root = new TreeNode(*pre_first);

		auto inRightPos = find(in_first, in_last, *pre_first);
		auto rightSize = distance(next(inRightPos), in_last);

		root->right = buildTree(next(pre_first), next(pre_first, rightSize + 1), next(inRightPos), in_last);
		root->left = buildTree(next(pre_first, rightSize + 1), pre_last, in_first, inRightPos);

		return root;
	}
};

int main()
{
	Solution s;
	
	TreeNode* root = s.buildTree(vector < int > {2, 3, 1}, vector < int > {3, 2, 1});

	return 0;
}