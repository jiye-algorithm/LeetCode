
#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
	vector<int> grayCode(int n) {

		vector<int> result;
		size_t size = 1 << n;

		result.reserve(size);

		for (size_t i = 0; i < size; ++i)
		{
			result.push_back(binaryToGray(i));
		}

		return result;
	}

private:
	unsigned int binaryToGray(size_t n)
	{
		return n ^ (n >> 1);
	}
};