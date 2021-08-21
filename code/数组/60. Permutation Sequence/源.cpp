/************************************************************************/
/*   
	暴力解决方案， 调用  k-1 次  next_permutation

	经过手动在纸上演示， 还真个可以解决这个问题， why

*/
/************************************************************************/
#include <iostream>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		for (int i = 0; i < n; ++i)
		{
			s[i] += i + 1;
		}

		for (int i = 0; i < k - 1; ++i)
		{
			next_permutation(s.begin(), s.end());
		}

		return s;
	}

	template <typename BidiIt>
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