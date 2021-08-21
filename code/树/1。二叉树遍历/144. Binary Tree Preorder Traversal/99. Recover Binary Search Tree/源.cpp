#include <vector>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode* root) {

		pair<TreeNode*, TreeNode*> broken;
		TreeNode* prev = nullptr;
		TreeNode* cur = root;
		while (cur != nullptr) {
			if (cur->left == nullptr) {
				detect(broken, prev, cur);
				prev = cur;
				cur = cur->right;
			}
			else {
				auto node = cur->left;
				while (node->right != nullptr && node->right != cur)
					node = node->right;
				if (node->right == nullptr) {
					node->right = cur;
					//prev = cur; 不能有这句！因为cur 还没有被访问
					cur = cur->left;
				}
				else {
					detect(broken, prev, cur);
					node->right = nullptr;
					prev = cur;
					cur = cur->right;
				}
			}
		}
		swap(broken.first->val, broken.second->val);
	}
	void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev,
		TreeNode* current) {
		if (prev != nullptr && prev->val > current->val) {
			if (broken.first == nullptr) {
				broken.first = prev;
			} //不能用else，例如{0,1}，会导致最后swap 时second 为nullptr，
			//会Runtime Error
			broken.second = current;
		}
	}
};