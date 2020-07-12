#include<bits/stdc++.h>
using namespace std;

void zhaodie(long long int& son)
{
	son = son/2;
}

void printArray(vector<int>& v) {

	for (int i = 0; i<v.size(); i++) {
		cout << v[i] << endl;
	}

}

int main()
{
    //cout << 1 / 2 << endl;
	int n;
	cin >> n;
	vector<int> res;

	for (size_t i = 0; i < n; i++)
	{
		long long int son;
		int k;
		cin >> son >> k;

		if (pow(2,k)>son)
		{
			res.push_back(-1);
			continue;
		}
		while (son>=1)
		{
			if (son >= pow(2, k-1) && son <pow(2, k))
			{
				res.push_back(son);
				break;
			}
			else
			{
				zhaodie(son);
			}
		}
		
	}

	printArray(res);

	getchar();
	getchar();

	return 0;
}