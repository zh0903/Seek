#include<bits/stdc++.h>
using namespace std;
#include "cinexp.h"
//牛客华为5.13笔试第一题输入
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//        vector<int> fir(3);
//		vector<int> sec(3);
//		char temp;
//		int wd;
//		for (int i = 0; i<3; i++) {
//			cin >> fir[i];
//		}
//		cin >> wd;
//		cin >> temp;
//		for (int i = 0; i<3; i++) {
//			cin >> sec[i];
//		}
//	}
//	
//	return 0;
//}


void cinexp::cinstring()
{
	string str;
	while (cin >> str)
		//jack　　　　bullshit　　jack
		//cin会接受空格 C++11
	{
		string bullshit = "bullshit";
		string bush = "bush";
		size_t pos = str.find(bullshit, 0);
		size_t length = 8;
		if (pos != string::npos)
			str.replace(pos, length, bush);
		cout << str;
	}
}
void cinexp::cinMutilineNum()
{
	vector<vector<int>> data(2);
	int tmp;
	int m;
	cin >> m;
	for (size_t i = 0; i < m; i++)
	{
		while (cin >> tmp) {
			data[i].push_back(tmp);
			if (cin.get() == '\n')
				break;
		}

	}
	cout << data[1][0];
}