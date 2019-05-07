// 这个代码真的是太漂亮了， 一下子点燃了我所有的对于算法的梦想， 对于未来的很多向往

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
		int sum = 0;
		while (x > sum)
		{
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		return (x == sum) || (x == sum / 10);
	}
};