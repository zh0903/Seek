// ConsoleApplication00.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


using namespace std;

int argmax(const int a[], int len) {
	int max = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] > a[max])
			max = i;
	}
	return max;
}
int main() {
	int m, k;
	int n = 0;
	int *chiken;
	cin >> n >> m >> k;
	if (m <= 100000 && m >= 1 && n <= 100000 && n >= 1 && k <= 10000 && k >= 1) {

		chiken =new int[n];
		int temp, i = 0;
		int sum = 0;
		int maxfarm;
		while (cin >> temp)
		{
			if (temp >= 1 && temp <= 100000)
			{
				chiken[i] = temp;
				++i;
			}
			else {
				return -1;
			}
		}
		for (int j = 0; j <= m - 1; ++j) {
			for (i = 0; i < n - 1; ++i) {
				chiken[i] += k;
			}
			maxfarm = argmax(chiken, n);
			chiken[maxfarm] /= 2;
		}
		for (i = 0; i < n; i++)
		{
			sum += chiken[i];
		}
		return sum;

	}
	else {
		return -1;
	}
	}
