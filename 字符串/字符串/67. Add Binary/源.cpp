#include <algorithm>
#include <string>

using namespace  std;

class Solution {
public:
	string addBinary(string a, string b) {

		int n = a.size() < b.size() ? b.size() : a.size();

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		string ans;

		int carry = 0;
		for (int i = 0; i < n; ++i)
		{
			int num1 = i < a.size()? a[i]-'0' : 0;
			int num2 = i < b.size() ? b[i]-'0' : 0;
			int num = num1 + num2 + carry;
			carry = num / 2;
			ans.insert(ans.begin(), num  % 2 + '0');
		}

		if (carry > 0)
			ans.insert(ans.begin(), carry + '0');

		return ans;
	}
};