//#include<bits/stdc++.h>
//using namespace std;
//
//void printResult(vector<vector<int> >& result)
//{
//	for (int i = 0; i<result.size(); i++) {
//		for (int j = 0; j<result[i].size(); j++) {
//			cout << result[i][j] << endl;
//		}
//
//	}
//}
//
//
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	stack<int> a, b;
//
//	int k;
//	cin >> k;
//	vector<int> res;
//
//	for (size_t i = 0; i < k; i++)
//	{
//		int n;
//		int num;
//		string temp;
//		cin >> temp;
//
//
//		if (temp == "add")
//		{
//			cin >> num;
//		    a.push(num);
//		}
//		if (temp == "peek")
//		{
//			if (b.empty())
//			{
//				while (!a.empty())
//				{
//					num = a.top();
//					b.push(num);
//					a.pop();
//				}
//				res.push_back(b.top());
//			}
//			else
//			{
//				res.push_back(b.top());
//			}
//		}
//		if (temp == "poll")
//		{
//			if (b.empty())
//			{
//				while (!a.empty())
//				{
//					num = a.top();
//					b.push(num);
//					a.pop();
//				}
//				b.pop();
//			}
//			else
//			{
//				b.pop();
//			}
//		}
//		
//
//	}
//
//	system("pause");
//	return 0;
//}
//
