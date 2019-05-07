#include <algorithm>
#include <map>
#include <list>

using namespace std;

class LRUCache{
public:
	LRUCache(int capacity) {
		this->capaity = capacity;
	}

	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end()) return -1;

		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		
		return cacheMap[key]->value;
	}

	void set(int key, int value) {

		if (cacheMap.find(key) == cacheMap.end())
		{
			if (cacheList.size() == capaity)
			{
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}

			cacheList.push_front(cacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
			cacheMap[key]->value = value;
		}
			
	}

private:

	struct cacheNode{
		int key;
		int value;
		cacheNode(int key, int value) : key(key), value(value){}
	};

	int capaity;
	list<cacheNode> cacheList;
	map<int, list<cacheNode>::iterator> cacheMap;
};