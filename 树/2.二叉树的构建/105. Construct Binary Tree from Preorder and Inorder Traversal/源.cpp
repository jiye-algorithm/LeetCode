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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}

private:
	template<typename InputIterator>
	TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last,
										InputIterator in_first, InputIterator in_last)
	{
		if (pre_last == pre_first) return NULL;
		if (in_first == in_last) return NULL;

		TreeNode* root = new TreeNode(*pre_first);

		auto inRootPos = find(in_first, in_last, *pre_first);
		auto leftSize = distance(in_first, inRootPos);

		root->left = buildTree(next(pre_first), next(pre_first, leftSize + 1), in_first, next(in_first, leftSize));
		root->right = buildTree(next(pre_first, leftSize + 1), pre_last, next(in_first, leftSize + 1), in_last);

		return root;
	}
};