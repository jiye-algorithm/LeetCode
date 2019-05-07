/************************************************************************/
/* 
	算法我连题目都没有看懂什么意思， 感觉代码大多使用了原来 c++ 一些技巧， 
	很特别， 

	其实算法关键还是思路问题， 思路对了， 语言就是优化的工具， 熟练使用一门语言可以减少代码量， 
	提高代码的效率
*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
	}

	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last)
	{
		const auto rFirst = reverse_iterator<BidiIt>(last);
		const auto rLast = reverse_iterator<BidiIt>(first);

		auto pivot = next(rFirst);

		while (pivot != rLast && !(*pivot < *prev(pivot)))
		{
			++pivot;
		}

		if (pivot == rLast)
		{
			reverse(rFirst, rLast);
			return false;
		}

		auto change = find_if(rFirst, pivot, bind1st(less<int>(), *pivot));

		swap(*change, *pivot);

		reverse(rFirst, pivot);

		return true;
	}
};