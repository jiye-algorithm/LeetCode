
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		stack<string> vec;
		stack<int> st;
		
		string str ="";
		int size = s.size();
		for (int i = 0; i < size;)
		{
			if (s[i] == ' ') {
				vec.push(str);
				str = "";

				int n = 1;
				++i;
				while (i < size && s[i + 1] == ' ')
				{
					i++;
				}
				st.push(n);
				continue;
			}
			str += s[i];
			++i;
		}

		vec.push(str);

		s = "";
		while (!vec.empty())
		{
			s += vec.top(); vec.pop();
			if (!st.empty())
			{
				s += " ";
				st.pop();
			}
		}

	}
};

//int main()
//{
//	string s = "the sky is blue";
//
//	Solution solu;
//	solu.reverseWords(s);
//
//	cout << s;
//
//	return 0;
//}