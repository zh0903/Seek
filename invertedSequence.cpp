#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int cnt = 0;
	int InversePairs(vector<int> data) {
		mergeSort(data, 0, data.size() - 1);
		return cnt % 1000000007;
	}
	void mergeSort(vector<int>& data, int begin, int end) {
		if (begin == end)
			return;
		//自底向上 未曾设想的道路
		int mid = (end - begin) / 2 + begin;
		mergeSort(data, begin, mid);
		mergeSort(data, mid + 1, end);
		merge(data, begin, mid, mid + 1, end);
	}
	void merge(vector<int>& data, int lbegin, int lend, int rbegin, int rend) {
		vector<int> tmp(rend - lbegin + 1);
		int t = 0;
		int p1 = lbegin, p2 = rbegin;
		while (p1 <= lend&&p2 <= rend) {
			if (data[p1] <= data[p2]) {
				tmp[t++] = data[p1++];
			}
			else {
				//包括p1在内后面所有的数字都与p2组成逆序.
				cnt += (lend - p1 + 1);
				tmp[t++] = data[p2++];
			}
		}
		while (p1 <= lend) {
			tmp[t++] = data[p1++];
		}
		while (p2 <= rend) {
			tmp[t++] = data[p2++];
		}
		for (int i = 0; i<tmp.size(); i++) {
			data[lbegin++] = tmp[i];
		}
	}
};