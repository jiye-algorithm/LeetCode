#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {

		int size = str.size();
		
		if (size == 0) return 0;

		str = str.substr(str.find_first_not_of(' '), str.size());

		bool tag = false;
		if (str[0] == '-') {
			tag = true;
			str = str.substr(1, str.size());
		}
		else if (str[0] == '+')
		{
			str = str.substr(1, str.size());
		}

		size = str.size();

		if (size == 0) return 0;

		int i = str.find_first_not_of("0");
		str = str.substr(i, str.size());

		size = str.size();

		if (size == 0) return 0;

		int ans = 0;
		 i = 0;
		for (; i < size; ++i)
		{
			if (!isdigit(str[i]))
			{
				break;
			}

			if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && str[i] >= '8')
			{
				if (tag) return INT_MIN;
				return INT_MAX;
			}

			ans = ans * 10 + (str[i] - '0');
		}

		if (i != size)
			if (tag == true)
				return -ans;

		if (tag)
			return -ans;

		return ans;
	}
};

int main()
{
	string s = "-2147483648";

	Solution solu;
	int ans = solu.myAtoi(s);

	return ans;

	return 0;
}