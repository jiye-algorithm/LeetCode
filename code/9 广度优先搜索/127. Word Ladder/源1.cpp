#include <string>
#include <queue>
#include <unordered_set>

using namespace  std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

		if (beginWord.size() != endWord.size()) return 0;
		if (beginWord.empty() || endWord.empty()) return 0;

		int level = 0;
		queue<string> current, next;
		unordered_set<string> visited;
		bool found = false;
		current.push(beginWord);
		while (!found && !current.empty())
		{
			level++;
			while (!found && !current.empty())
			{
				string str(current.front()); current.pop();

				for (size_t i = 0; i < str.size(); ++i)
				{
					string new_word(str);
					for (char c = 'a'; c < 'z'; ++c)
					{
						if (c == new_word[i]) continue;
						swap(c, new_word[i]);
						if (new_word == endWord)
						{
							found = true;
							break;
						}
						if (wordList.count(new_word) > 0 && !visited.count(new_word))
						{
							next.push(new_word);
							visited.insert(new_word);
						}

						swap(c, new_word[i]);
					}
				}
			}
			swap(next, current);
		}

		if (found) return level + 1;

		return 0;
	}
};

int main()
{
	Solution s;
	s.ladderLength("a", "c", unordered_set < string > {"a", "b", "c"});

	return 0;
}