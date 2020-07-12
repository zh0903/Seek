#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, L; cin >> n >> L;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i<n; ++i) cin >> vec[i].first >> vec[i].second;
	sort(vec.begin(), vec.end());
	if (vec[0].first>0) { cout << -1; return 0; }//teshuqingkuang
	int right = 0;
	int i = 0;
	int res = 0;
	while (i<n) {
		int r = right;
		for (; i<n && vec[i].first <= r; ++i) {
			right = max(right, vec[i].second);
		}
		++res;
		if (right >= L) { cout << res; return 0; }
		if (i >= n || vec[i].first>right) { cout << -1; return 0; }
	}
	return 0;

}
