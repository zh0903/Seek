#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100001; //´úÌædefine
int nextTable[MAX_N];
 
struct Node{
	int from;
	int to;
	Node(int f, int t):from(f), to(t){};
};
 
vector<string> strList;
vector<Node> nodeList;


int main(int argc, char**argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	while (cin >> n)
	{
		strList.clear();
		nodeList.clear();
		for (size_t i = 0; i < n; i++)
		{
			cin >> s;
			strList.push_back(s);
		}
		cin >> s;
	}
	cout << s << endl;
	system("pause");

}