#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {

		int x, y;
		auto token = tokens.back(); tokens.pop_back();

		if (isOperator(token))
		{
			y = evalRPN(tokens);
			x = evalRPN(tokens);
			if (token == "+") x += y;
			else if (token == "-") x -= y;
			else if (token == "*") x *= y;
			else x /= y;
		}
		else
		{
			size_t i;
			x = stoi(token, &i);
		}

		return x;
	}

private: 
	bool isOperator(const string& s)
	{
		return s.size() == 1 && string("+-*/").find(s) != string::npos;
	}
};