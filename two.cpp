//#include<bits/stdc++.h>
//#include <iomanip>
//using namespace std;
//
//void printResult(vector<vector<int> >& result)
//{
//	for (int i = 0; i<result.size(); i++) {
//		for (int j = 0; j<result[i].size(); j++) {
//			cout <<setprecision(2) << result[i][j] << endl;
//		}
//
//	}
//}
//
//void printArray(vector<float>& v) {
//	
//	for (int i = 0; i<v.size(); i++) {
//		cout << setprecision(3) << v[i]<<endl;
//	}
//}
//
//float dist(pair<float, float> a, pair<float, float> b) 
//{
//	return sqrt(pow(2, (a.first - b.first))+pow(2, (a.second - b.second)));
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int k, n;
//	cin >> k;
//
//	vector<float> res(k);
//
//	for (size_t i = 0; i < k; i++)
//	{
//		pair<float, float> temp;
//
//		cin >> n;	
//
//		for (size_t j = 0; j < 2*n; j++)
//		{
//			vector<pair<float, float>> pointt(2*n);
//			cin >> temp.first;
//			cin >> temp.second;
//			pointt.push_back(temp);
//
//			float mindis = 1e20;
//			for (size_t i = 0; i < n; i++)
//			{
//				for (size_t j = n; j < 2 * n; j++)
//				{
//					mindis = (dist(pointt[i], pointt[j]) < mindis) ? dist(pointt[i], pointt[j]) : mindis;
//				}
//			}
//			res.push_back(mindis);
//		}
//	}
//	printArray(res);
//
//	system("pause");
//	return 0;
//}