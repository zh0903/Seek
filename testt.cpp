// testt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string> 
#include<vector>
using namespace std;
int main()
{
	int temp;
	int i = 0;
	vector<vector<int>> continuousSubs;
	vector<vector<int>>::iterator  taill;
	vector<int> tempvec;
	vector<int> test;
 	while (cin >> temp) {
		test[i++] = temp;
	}

	for (size_t j = 0; j < test.size(); j++)
	{
		temp = test[j];
		tempvec.push_back(temp);

		if (j == 0) {
			continuousSubs.push_back(tempvec);
			continue;
		}
		for (taill = continuousSubs.end(); taill >= continuousSubs.end()-j-1;taill--) {
			
			(*taill).push_back(temp);
		  
		}
		continuousSubs.push_back(tempvec);
	}
	/*for (size_t i = 0; i < n; i++)	{
		cout << test[i];
	}*/
    

	


}


//我要输入一个数组，但是数组不知道确切大小，比如我输入1 2 3 4然后按回车键却不能结束，怎样才能按回车键结束呢

//int main()
//{
//	int arr[100];
//	int temp;
//	int count = 0;
//	char c;
//	while (((cin >> temp).get(c)))
//	{
//
//		arr[count] = temp;
//		if (c == '\n')
//			break;
//		count++;
//		if (count >= 100)
//			break;
//	}
//	for (int i = 0; i <= count; i++)
//		cout << arr[i];
//	system("pause");
//	return 0;
//
//}
