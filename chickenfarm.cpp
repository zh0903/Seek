// chickenfarm.cpp : 定义控制台应用程序的入口点。
//

#include "queue"
#include<iostream>
using namespace std;

int main()
{
	int n, m, k, t;
	long long  base(0),sum(0);//定义
	cin >> n >> m >> k;
	priority_queue<int> heap;//默认大根堆
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		heap.emplace(t);//入堆
		sum += t;//求鸡的总和
	}
	for (size_t i = 0; i < m; i++)
	{
		base += k;
		t = heap.top() + base;
		heap.pop();
		heap.emplace(t/2-base);//保持队列内都是不增加状态
		sum -= t / 2;
	}
	cout << base*n + sum << endl;
	getchar();
	getchar();
	return 0 ;
}

