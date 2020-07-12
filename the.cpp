//#include<bits/stdc++.h>
//#include <iomanip>
//using namespace std;
//
//void printResult(vector<vector<int> >& result)
//{
//	for (int i = 0; i<result.size(); i++) {
//		for (int j = 0; j<result[i].size(); j++) {
//			cout << setiosflags(ios::fixed) << setprecision(2) << result[i][j] << endl;
//		}
//
//	}
//}
//
//void printArray(vector<float>& v) {
//
//	for (int i = 0; i<v.size(); i++) {
//		cout << setprecision(3) << v[i] << endl;
//	}
//}
//
//
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n, m;
//	vector<set<int>> reader;
//	set<int> a;
//
//	
//	cin >> n >> m;
//	vector<int> soccer(n,0);
//	for (size_t i = 0; i < m; i++)
//	{
//		int temp;
//		while (cin>>temp)
//		{
//			reader[i].insert(temp);
//		}
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		for (size_t j = 0; j < m; j++)
//		{
//			if (reader[j].count(i) == 1)
//				soccer[i]++;
//		}
//		
//	}
//	int max = 0;
//	int maxidx;
//	for (size_t i = 0; i < n; i++)
//	{
//		if (soccer[i]>max)
//		{
//			max = soccer[i];
//			maxidx = i;
//		}
//	}
//
//	for (size_t i = 0; i < m; i++)
//	{
//		if (reader[i].count(maxidx) == 1)
//			reader.erase(reader[i]);
//	}
//
//
//
//	system("pause");
//	return 0;
//}