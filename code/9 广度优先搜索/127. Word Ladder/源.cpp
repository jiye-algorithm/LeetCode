#include <string>
#include <unordered_set>

using namespace  std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

		vector<string> path;

		bool flag = false;
		path.push_back(beginWord);
		int count = 0;
		ladderLength(beginWord, endWord, wordList, flag, path, count);

		return count;
	}

private:
	void ladderLength(string beginWord, string endWord, unordered_set<string>& wordList, bool& flag, vector<string>& path, int& count)
	{

		if (distanceTwoWord(beginWord, endWord) == 1)
		{
			flag = true;
			path.push_back(endWord);
			count = path.size();
			return;
		}

		for (auto i = wordList.begin(); i != wordList.end() && flag == false; ++i)
		{
			// 找到 链表中 与 beginWord 差1 的元素
			if (distanceTwoWord(*i, beginWord) == 1)
			{
				// 看是否找到
				// 该元素是否已经找过了
				if (find(path.begin(), path.end(), *i) != path.end()) continue;
				// 以该元素为头 重复
				path.push_back(*i);
				ladderLength(*i, endWord, wordList, flag, path, count);
				path.pop_back();
			}
		}
	}


	int distanceTwoWord(string a, string b)
	{
		int count = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] != b[i]) count++;
		}

		return count;
	}
};

