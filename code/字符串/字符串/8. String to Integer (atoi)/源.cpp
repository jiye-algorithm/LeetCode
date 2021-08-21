#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {

		int num = 0;
		int i = 0;
		int n = str.size();
		int sign = 1;

		while (i < n && str[i] == ' ') ++i;


		if (str[i] == '+') ++i;

		else if (str[i] == '-')
		{
			sign = -1;
			++i;
		}

		for (; i < n; ++i)
		{
			if (str[i] < '0' || str[i] > '9') break;

			if (num > INT_MAX / 10 ||
				(num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
			{
				return sign == -1 ? INT_MIN : INT_MAX;
			}

			num = num * 10 + str[i] - '0';
		}

		return num * sign;
	}
};