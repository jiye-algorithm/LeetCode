#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {

		vector<string> dirs;

		for (auto i = path.begin(); i != path.end();)
		{
			++i;

			auto j = find(i, path.end(), '/');
			string dir = string(i, j);

			if (!dir.empty() && dir != ".")
			{
				if (dir == "..")
				{
					if (!dirs.empty())
						dirs.pop_back();
				}
				else
					dirs.push_back(dir);
			}

			i = j;
		}
	
		if (dirs.empty()) return "/";

		stringstream ss;
		for (auto dir : dirs)
			ss << '/' << dir;

		return ss.str();

	}
};