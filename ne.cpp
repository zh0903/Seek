//#include <iostream>
//#include <math.h>
//#include <vector>
//using namespace std;
//
//void judge( vector<vector<char>>& map, int& len,const int posx,const int posy) {
//	for (int i = posx-len; i <posx+len&&i<map.size(); i++)
//	{
//		if (i<=0)
//		{
//			i = 0;
//		}
//		for (int j = posy-len; j < posy+len&&j<map.size(); j++)
//		{
//			if (j<=0)
//			{
//				j = 0;
//			}
//			if (map[i][j]>0&& len>sqrt((double)pow((posx-i),2)+ (double)pow((posy - j), 2)))
//			{
//				len = len + (int)map[i][j];
//			}
//		}
//
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//
//	for (size_t k = 0; k < t; k++)
//	{
//		int m, len;
//		cin >> m >> len;
//		vector<vector<char>> map;
//		vector<char> tempv;
//		int temp;
//		for (size_t i = 0; i < m; i++)
//		{
//			for (size_t j = 0; j < m; j++)
//			{
//				cin >> temp;
//				tempv.push_back(temp);
//			}
//			map.push_back(tempv);
//		}
//		int posx, posy;
//		cin >> posx >> posy;
//		int prelen = len;
//		while (1)
//		{
//			judge(map, len, posx, posy);
//			if (len>temp)
//			{ 
//				temp = len;
//				continue;
//			}
//			else
//			{
//				break;
//			}
//		}
//		 cout<<len;
//		
//	}
//	return 0;
//}