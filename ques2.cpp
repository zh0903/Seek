#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<int> result;
	for (int k = 0; k < t; k++)
	{
		int n, m;
		cin >> n >> m;
		vector<set<int>> allset;
		set<int> number;

		for (int i = 0; i < m; i++)
		{
			int typee;
			int num1, num2;
			scanf_s("%d", &typee);
			if (typee == 1)
			{
				
				scanf_s("%d", &num1);
				scanf_s("%d", &num2);
				for (int i = 0; i < allset.size(); i++)
				{
					if ((allset[i].count(num1) != 0) && (allset[i].count(num2) != 0))
					{
						break;
					}
					else
					{
						if (allset[i].count(num1) != 0)
						{
							allset[i].erase(num1);
						}
						if (allset[i].count(num2) != 0)
						{
							allset[i].erase(num2);
						}
					}
				}
				number.insert(num1);
				number.insert(num2);
				allset.push_back(number);
				number.clear();
			}
			if (typee == 2)
			{
				scanf_s("%d", &num1);
				for (int i = 0; i < allset.size(); i++)
				{
					if (allset[i].count(num1) == 0)
					{
						continue;
					}
					else
					{
						allset[i].erase(num1);
					}
				}
			}
			if (typee == 3)
			{
				int num1;
				scanf_s("%d", &num1);
				for (int i = 0; i < allset.size(); i++)
				{
					if (allset[i].count(num1) == 0)
					{
						continue;
					}
					else
					{
						result.push_back(allset[i].size());
						break;
					}
				}
				result.push_back(1);
			}
		}
	}
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i]<<endl;
	}
	getchar();
	getchar();
	return 0;

}
