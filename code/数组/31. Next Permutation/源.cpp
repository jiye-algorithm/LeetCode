/************************************************************************/
/* 
	�㷨������Ŀ��û�п���ʲô��˼�� �о�������ʹ����ԭ�� c++ һЩ���ɣ� 
	���ر� 

	��ʵ�㷨�ؼ�����˼·���⣬ ˼·���ˣ� ���Ծ����Ż��Ĺ��ߣ� ����ʹ��һ�����Կ��Լ��ٴ������� 
	��ߴ����Ч��
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