#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

void printResult(vector<vector<int> >& result)
{
	for (int i = 0; i<result.size(); i++) {
		for (int j = 0; j<result[i].size(); j++) {
			cout << setiosflags(ios::fixed) << setprecision(2) << result[i][j] << endl;
		}

	}
}

void printArray(vector<float>& v) {

	for (int i = 0; i<v.size(); i++) {
		cout << setprecision(3) << v[i] << endl;
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while (cin >> s)
	{
		auto tail = s.end();
		for (auto i = s.end()-1; i!=s.begin();--i)
		{
			if (*i>='A'&&*i<='Z')
			{
				
			}
		}
	}



	system("pause");
	return 0;
}