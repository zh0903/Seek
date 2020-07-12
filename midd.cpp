#include "stdafx.h"//StandardApplication Framework Extensions
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<int> temp(n, 0);
//	vector<int> pos;
//	for (size_t i = 0; i < n; ++i)
//	{
//		cin >> temp[i];
//	}
//	for (size_t i = 0; i < temp.size(); ++i)
//	{
//		if (temp[i] == k)
//		{
//			break;
//		}
//		else
//		{
//			temp.push_back(k);
//		}
//	}
//
//	sort(temp.begin(), temp.end());
//
//	for (size_t j = 0; j < temp.size(); ++j)
//	{
//		if (temp[j]==k)
//		{
//			pos.push_back(j);
//		}
//	}
//	int min = abs(pos[0] - (n + 1) / 2);
//	for (size_t l = 1; l < pos.size(); ++l)
//	{
//		if (abs(pos[l] - (n + 1) / 2)<min)
//		{
//			min = abs(pos[l] - (n + 1) / 2);
//		}
//	}
//
//	cout << min << endl;
//
//	getchar();
//	getchar();
//	return 0;
//}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> temp(n, 0);
	vector<int> pos;
	for (size_t i = 0; i < n; ++i)
	{
		cin >> temp[i];
	}
	for (size_t i = 0; i < temp.size(); ++i)
	{
		if (temp[i] == k)
		{
			break;
		}
		else
		{
			temp.push_back(k);
		}
	}

	sort(temp.begin(), temp.end());

	for (size_t j = 0; j < temp.size(); ++j)
	{
		if (temp[j] == k)
		{
			pos.push_back(j);
		}
	}
	int min = abs(pos[0] - (n + 1) / 2);
	for (size_t l = 1; l < pos.size(); ++l)
	{
		if (abs(pos[l] - (n + 1) / 2)<min)
		{
			min = abs(pos[l] - (n + 1) / 2);
		}
	}

	cout << min << endl;

	getchar();
	getchar();
	return 0;
}