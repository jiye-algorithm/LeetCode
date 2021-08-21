#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int j = -1;
		int total = 0;

		for (int i = 0, sum = 0; i < gas.size(); ++i)
		{
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];

			if (sum < 0)
			{
				j = i; 
				sum = 0;
			}
		}

		return total < 0 ? -1 : j + 1;
	}
};