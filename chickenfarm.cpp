// chickenfarm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "queue"
#include<iostream>
using namespace std;

int main()
{
	int n, m, k, t;
	long long  base(0),sum(0);//����
	cin >> n >> m >> k;
	priority_queue<int> heap;//Ĭ�ϴ����
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		heap.emplace(t);//���
		sum += t;//�󼦵��ܺ�
	}
	for (size_t i = 0; i < m; i++)
	{
		base += k;
		t = heap.top() + base;
		heap.pop();
		heap.emplace(t/2-base);//���ֶ����ڶ��ǲ�����״̬
		sum -= t / 2;
	}
	cout << base*n + sum << endl;
	getchar();
	getchar();
	return 0 ;
}

