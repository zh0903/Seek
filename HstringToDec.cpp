//#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int hexToDec(char c)
{
	return (c-'a'>0)?(c-'a'+10):(c-'0');
}

int main()
{
	string s;
	while (cin>>s)
	{
		int n = s.size();
		int x = 0;
		for (int i = 2; i < n; i++)
		{
			cout << hexToDec(s[i])<<endl;
			x = x * 16 + hexToDec(s[i]);
		}
		cout << x << endl;
	}
	system("pause");
	return 0;
}

//string x;
//cin >> x;
//stringstream stream(x);
//
//int s=0;
//stream >> s;
//cout << s;
//system("pause");


//void str2int(int &int_temp, const string &string_temp)
//{
//	stringstream stream(string_temp);
//	//stream<<string_temp;
//	stream >> int_temp;
//}
//
//int main()
//{
//	string hnum;
//	int temp;
//	while (cin>>hnum)
//	{
//		str2int(temp, hnum);
//		cout << temp << endl;
//	}
//	return 0;
//}