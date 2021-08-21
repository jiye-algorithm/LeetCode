#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {

		vector<vector<string> > ans;
		vector<string> path;

		if (beginWord.size() != endWord.size()) return ans;
		if (beginWord.empty() || endWord.empty()) return ans;

		path.push_back(beginWord);
		findLadders(beginWord, endWord, wordList, path, ans);

		return ans;
	}

private:
	void findLadders(string beginWord, string endWord, unordered_set<string> &wordList, vector<string>& path, vector<vector<string> >& ans)
	{
		if (path.back() == endWord)
		{
			ans.push_back(path);
			return;
		}

		for (auto iter = wordList.find(beginWord); iter != wordList.end(); ++iter)
		{
			if (find(path.begin(), path.end(), *iter) != path.end()) continue;

			for (int i = 0; i < (*iter).size(); ++i)
			{
				string new_word(*iter);
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == new_word[i]) continue;

					swap(c, new_word[i]);

					if (new_word == endWord)
					{
						path.push_back(endWord);
						findLadders(beginWord, endWord, wordList, path, ans);
						path.pop_back();
						continue;
					}

					if (wordList.count(new_word) > 0 && find(path.begin(), path.end(), new_word) == path.end())
					{
						path.push_back(new_word);
						findLadders(new_word, endWord, wordList, path, ans);
						path.pop_back();
						continue;
					}

					swap(c, new_word[i]);
				}
			}
		}
	}
};

int main()
{
	Solution s;
	s.findLadders("hot", "cog", unordered_set < string > { "hot", "dot", "dog", "lot", "log"});

	return 0;
}