
/************************************************************************/
/* 
	��һ�ִ������ֱ�ӱ����ķ�ʽ�� ���ʹ��ʱ�䳬����

	����Ĵ������õ�˼·
		* ���ÿռ任ȡ�˲���ʱ��
		* ������ʱ��ĳɱ�
	
	�������漰����˼��
		* ���� map ����ṹ�� �������õ� map  �� key -��value ���ܣ� �ɹ����������Ϊ key �� ������֮�������Ĳ���
		* ���� set �Ĳ��ع��ܣ� ʵ���˲��أ� Ч��

*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		if (nums.size() < 4) return 	vector<vector<int> >();
		sort(nums.begin(), nums.end());

		map<int, vector<pair<int, int>  > > cache;
		// �Ƚ�ǰ�������ݱ��滺�������� ���� map ��������������ݽṹ�� �����������ӹ�
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				cache[nums[i] + nums[j]].push_back(pair < int, int > (i, j));
			}
		}

		set<vector<int> > result;
		// �ж���ȡ����������
		for (int a = 2; a < nums.size(); ++a)
		{
			for (int b = a + 1; b < nums.size(); ++b)
			{
				const int key = target - nums[a] - nums[b];
				if (cache.find(key) != cache.end())
				{
					for (int c = 0; c < cache[key].size(); ++c)
					{
						if (a <= cache[key][c].second) continue;

						result.insert(vector < int > {nums[cache[key][c].first], nums[cache[key][c].second], nums[a], nums[b]});
					}
				}
			}
		}

		return vector<vector<int> >(result.begin(), result.end());
	}
};