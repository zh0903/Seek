#include<bits/stdc++.h>
using namespace std;
class solution
{
public:
	solution();
	~solution();
	int count(vector<vector<char>> map)
	{
		int count = 0;
		for (size_t i = 0; i < map.size(); i++)
		{
			for (size_t j = 0; j < map[0].size; j++)
			{
				if (map[i][j]=='1')
				{
					dfs(map,i,j);
					count+=1;
				}
			}
		}
		return count;
	}

	void dfs(vector<vector<char>> &map, const int i, const int j)
	{
		if (i<0||j<0||i>=map.size()||j>=map[0].size()||map[i][j]==0)
		{
			return;
		}
		map[i][j] ='0';
		dfs(map, i, j - 1);
		dfs(map, i-1, j);
		dfs(map, i, j + 1);
		dfs(map, i+1, j );
	}
private:

};

solution::solution()
{
}

solution::~solution()
{
}