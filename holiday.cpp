#include<iostream>
#include<algorithm>
using namespace std;

int w[100005];
int p[100005];
int dp[100005][2];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> p[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][1] + w[i], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0] + p[i], dp[i - 1][1]);
	}

	cout << n - max(dp[n][0], dp[n][1])<<endl;
}
