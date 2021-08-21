#include <string>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {

		char* endPtr;

		strtod(s.c_str(), &endPtr);

		if (s.c_str() == endPtr) return false;

		for (; *endPtr; ++endPtr)
			if (!isspace(*endPtr)) return false;

		return true;

	}
};