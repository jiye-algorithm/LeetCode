#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {

		init();

		vector<string> ans;
		string path;

		letterCombinations(ans, path, digits, 0);

		return ans;

	}

private:
	vector<string> nums;

	void letterCombinations(vector<string>& ans, string& path, string digits, int step)
	{
		if (path.size() == digits.size() && path.find_first_not_of(' ') != -1)
		{
			ans.push_back(path);
			return;
		}

		if (step == digits.size()) return;

		for (int i = 0; i < nums[digits[step] - '0'].size(); ++i)
		{
			letterCombinations(ans, path, digits, step + 1);

			path += nums[digits[step] - '0'][i];
			letterCombinations(ans, path, digits, step + 1);
			path.pop_back();
		}

	}

	void init()
	{
		nums.resize(10);
		nums[0] = " ";
		nums[1] = "";
		nums[2] = "abc";
		nums[3] = "def";
		nums[4] = "ghi";
		nums[5] = "jkl";
		nums[6] = "mno";
		nums[7] = "pqrs";
		nums[8] = "tuv";
		nums[9] = "wxyz";
	}
};

int main()
{
	Solution s;
	s.letterCombinations("23");

	return 0;
}