#include <queue>

using namespace  std;

struct TreeLinkNode {
	int val;
	 TreeLinkNode *left, *right, *next;
	 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
	void connect(TreeLinkNode *root) {

		queue<TreeLinkNode*> cur, next;

		if (root == nullptr) return;

		cur.push(root);

		while (!cur.empty())
		{
			while (!cur.empty())
			{
				root = cur.front();	cur.pop();
				if (!cur.empty()) root->next = cur.front();

				if (root->left) next.push(root->left);
				if (root->right) next.push(root->right);
			} 
			root->next = nullptr;

			swap(cur, next);
		}

	}
};