#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
	void connect(TreeLinkNode *root) {

		if (root == nullptr) return;

		queue<TreeLinkNode*> cur, next;
		TreeLinkNode* p = root;
		cur.push(p);
		while (!cur.empty())
		{
			while (!cur.empty())
			{
				p = cur.front(); cur.pop();

				if (!cur.empty())
					p->next = cur.front();

				if (p->left) next.push(p->left);
				if (p->right) next.push(p->right);
			}

			p->next = nullptr;

			swap(cur, next);
		}

	}
};