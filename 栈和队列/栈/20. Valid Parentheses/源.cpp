#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {

		stack<char> sc;

		for (int i = 0; i < s.size(); ++i)
		{
			switch (s[i])
			{
			case '(' :
			case '{':
			case '[':
				sc.push(s[i]);			break;

			case ']':
				if (sc.empty()) return false;
				if (!sc.empty() && sc.top() == '[')
					sc.pop();
				else
					return false;
				break;
			case ')':
				if (sc.empty()) return false;
				if (!sc.empty() && sc.top() == '(')
					sc.pop();
				else
					return false;
				break;
			case '}':
				if (sc.empty()) return false;
				if (!sc.empty() && sc.top() == '{')
					sc.pop();
				else
					return false;
				break;
			default:
				break;
			}
		}

		return sc.empty();

	}
};