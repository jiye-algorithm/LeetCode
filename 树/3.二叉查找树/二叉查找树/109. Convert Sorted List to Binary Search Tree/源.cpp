#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
     int val;
    TreeNode *left;
   TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {

		TreeNode* root = nullptr;
		if (head == nullptr) return root;

		while (head)
		{
			insert(root, head->val);
			head = head->next;
		}

		return root;
	}

private:
	int height(TreeNode*& root)
	{
		if (root == nullptr) return 0;

		int left = height(root->left);
		int right = height(root->right);

		return left > right ? left + 1 : right + 1;
	}

	void insert(TreeNode*& root, int val)
	{
		if (root == nullptr)
		{
			root = new TreeNode(val);
			return;
		}

		if (root->val > val)
			 insert(root->left, val);
		else
			 insert(root->right, val);

		root = adjust(root);

	}

	TreeNode* adjust(TreeNode* root)
	{

		if (root == nullptr) return root;

		while (abs(height(root->left) - height(root->right)) > 1)
		{
			TreeNode* right = root->right;
			TreeNode* left = root->left;

			if (left)
			{
				root->right = right->left;
				right->left = root;
			}
			else
			{
				root->right = right->left;
				right->left = root;
			}
			root = right;
		}

		return root;
	}
};

int main()
{
	ListNode* head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);

	ListNode* temp3 = new ListNode(3);
	temp3->next = new ListNode(4);
	temp3->next->next = new ListNode(5);

	head->next->next->next = temp3;

	Solution s;
	s.sortedListToBST(head);

	return 0;
}