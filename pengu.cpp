//#include<bits/stdc++.h>
//using namespace std;
//
//void printResult(vector<vector<int> >& result)
//{
//	for (int i = 0; i<result.size(); i++) {
//		for (int j = 0; j<result[i].size(); j++) {
//			cout << result[i][j]<<endl;
//		}
//
//	}
//}
//
//void printArray(vector<int>& v) {
//	cout << "{";
//	for (int i = 0; i<v.size(); i++) {
//		cout << " " << v[i];
//	}
//	cout << " }" << endl;
//}
//
//int main()
//{ 
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//
//
//	int k, n;
//	cin >> k;
//	vector<vector<int>> res(k);
//	for (size_t i = 0; i < k; i++)
//	{
//		int n;
//		int num;
//		string temp;
//		cin >> n;
//		queue<int> test;
//		for (size_t j = 0; j < n; j++)
//		{
//			cin >> temp;
//			if (temp=="PUSH")
//			{
//				cin >> num;
//				test.push(num);
//			}
//			if (temp=="TOP")
//			{
//				res[i].push_back(test.empty() ? -1 : test.front());
//			}
//			if (temp=="POP")
//			{
//				if (test.empty())
//					res[i].push_back (-1);
//				else
//				{
//					test.pop();
//				}
//			}
//			if (temp=="CLEAR")
//			{
//				while (!test.empty())
//					test.pop();
//			}
//			if (temp=="SIZE")
//			{
//				res[i].push_back(test.size());
//			}
//		}
//
//	}
//
//	printResult(res);
//	system("pause");
//    return 0;
//}
//
