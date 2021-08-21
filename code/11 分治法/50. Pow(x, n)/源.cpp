#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {

		if (n > 0) return powP(x, n);
		if (n < 0) return powN(x, n);
		
		return 1;
	}

private:
	double powP(double x, int n)
	{
		double sum = 1;
		for (int i = 0; i < n; ++i)
		{
			sum *= x;
		}


		return sum;
	}

	double powN(double x, int n)
	{
		n = -n;
		double sum = 1;
		for (int i = 0; i < n; ++i)
		{
			sum *= x;
		}

		return 1 / sum;
	}
};