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
	TreeNode* sortedArrayToBST(vector<int>& nums) {

		return sortedArrayToBST(nums.begin(), nums.end());

	}

private:
	template<typename RandomAcessIterator>
	TreeNode* sortedArrayToBST(RandomAcessIterator first, RandomAcessIterator last)
	{
		int len = distance(first, last);

		if (len <= 0) return NULL;

		auto mid = first + len / 2;

		TreeNode* root = new TreeNode(*mid);
		root->left = sortedArrayToBST(first, mid);
		root->right = sortedArrayToBST(mid + 1, last);

		return root;
	}
};

