#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {

		add(digits, 1);

		return digits;
	}

private:
	void add(vector<int>& digits, int digit)
	{
		int carry = digit;

		for (auto it = digits.rbegin(); it != digits.rend(); ++it)
		{
			*it += carry;
			carry = *it / 10;
			*it = *it % 10;
		}

		if (carry > 0) digits.insert(digits.begin(), 1);

	}
};