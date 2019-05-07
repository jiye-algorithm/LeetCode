#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {

		this->n= nums.size();

		bool flag = false;
		dfs(nums, 0, flag);

		return flag;
	}

private: 
	int n;
	void dfs(vector<int>& nums, int now, bool& flag)
	{

		if (now >= n - 1)
		{
			flag = true;
			return;
		}

		if (flag) return;

		dfs(nums, now + nums[now], flag);

	}
};

int main()
{
	Solution s;
	s.canJump(vector < int > {0, 1});

	return 0;
}