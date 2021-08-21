
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> used;

		for (auto i : nums) used[i] = false;

		int longest = 0;

		for (auto i : nums)
		{
			if (used[i] == true) continue;

			used[i] = true;
			int length = 1;

			for (int j = i + 1; used.find(j) != used.end(); ++j)
			{
				length++;
				used[j] = true;
			}

			for (int j = i - 1; used.find(j) != used.end(); --j)
			{
				length++;
				used[j] = true;
			}

			longest = max(longest, length);
		}

		return longest;
	}
};