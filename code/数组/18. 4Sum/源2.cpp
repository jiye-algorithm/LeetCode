/************************************************************************/
/*   
	leetcode上的一段 c++ 代码， 很漂亮， 利用很多条件， 和颗粒代码， 成功避免了很多情况， 
	作者的思路很清晰

*/
/************************************************************************/


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> total;
		int n = nums.size();
		if (n < 4)  return total;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++)
		{
			if (i>0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1]<target) continue;
			for (int j = i + 1; j<n - 2; j++)
			{
				if (j>i + 1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2]>target) break;
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
				int left = j + 1, right = n - 1;
				while (left < right){
					int sum = nums[left] + nums[right] + nums[i] + nums[j];
					if (sum < target) left++;
					else if (sum > target) right--;
					else{
						total.push_back(vector < int > {nums[i], nums[j], nums[left], nums[right]});
						do{ left++; } while (nums[left] == nums[left - 1] && left < right);
						do{ right--; } while (nums[right] == nums[right + 1] && left < right);
					}
				}
			}
		}
		return total;
	}
};