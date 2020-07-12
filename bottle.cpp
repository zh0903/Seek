//#include<bits/stdc++.h>
//using namespace std;
//
//
//
//int main()
//{
//	int i;
//	while (cin >> i)
//	{
//		if (i == 0)
//			break;
//		cout << i / 2 << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	int n;
//	vector<int> result;
//	while(cin >> n)
//	{		
//		if (n==0)
//		{
//			break;
//		}
//		else
//		{
//			int max = 0;
//			int left = 0;
//			int drank = 0;
//			while ((left + drank) >= 2)
//			{
//				max += n / 3;
//				left = n % 3;
//				drank = n / 3;
//				n = left + drank;
//				if (n/3==0)
//				{
//					max+=n/2;
//					result.push_back(max);
//					break;
//				}
//
//			}
//		}
//
//
//	}
//	for (size_t i = 0; i < result.size(); i++)
//	{
//		cout << result[i] << endl;
//	}
//	getchar();
//	getchar();
//	return 0;
//}