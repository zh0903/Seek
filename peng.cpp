#include <bits/stdc++.h>

using namespace std;
void printResult(vector<vector<int> >& result)
{
	for (int i = 0; i<result.size(); i++) {
		cout << "{";
		for (int j = 0; j<result[i].size(); j++) {
			cout << " " << result[i][j];
		}
		cout << " }" << endl;
	}
}

void printArray(vector<int>& v) {
	cout << "{";
	for (int i = 0; i<v.size(); i++) {
		cout << " " << v[i];
	}
	cout << " }" << endl;
}
string decode(const string& str) 
{
	stack<int> counts;
	stack<string> prefixs;

	string res;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			int tmpcount = 0;
			while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
				tmpcount = tmpcount * 10 + (str[i] - '0');
				i++;
			}
			counts.push(tmpcount);
		}
		else if (str[i] == '[') {
			prefixs.push(res);
			res = "";
		}
		else if (str[i] == ']') {
			int c = counts.top();
			counts.pop();
			string pre = prefixs.top();
			prefixs.pop();
			for (int i = 0; i < c; i++) {
				pre.append(res);
			}
			res = pre;
		}
		else
			res.append(1, str[i]);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s = "";
	while (cin>>s)
	{
		cout << decode(s) << endl;
	}
    return 0;
}

