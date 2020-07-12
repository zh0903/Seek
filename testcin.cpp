#include<bits/stdc++.h>
#include"cinexp.h"
using namespace std;

int main()
{   
	//cinexp instance;
	//instance.cinMutilineNum();
	vector<int> fir(3);
	for (size_t i = 0; i < 3; i++)
	{
		cin >> fir[i];
	}
	for (size_t i = 0; i < 3; i++)
	{
		cout << fir[i] << endl;
		//输入任何非数字都会认为是间隔符 ，|
	}
	system("pause");
	return 0;
}