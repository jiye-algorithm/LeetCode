

#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	void reverseWords(string &s) {

		string str;
		int j = s.size();
		int size = s.size();

		for (int i = size - 1; i >= 0; --i)
		{
			if (s[i] == ' ')
			{
				j = i; 
			}
			else if (i == 0 || s[i - 1] == ' ')
			{
				if (str.size() != 0)
				{
					str += " ";
				}
				for (int k = i; k < j; ++k)
					str += s[k];
			}
		}
		s = str;
	}
};


