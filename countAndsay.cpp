// countAndsay.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class longest
{
public:
	longest();
	~longest();

	static int palindromic(string& s) {
		int max_len = 1;
		int start_index = 0;
		int len = s.length();
		vector<vector<int>> dp (len , vector<int>(len,0));
		for (size_t i = 0; i < len; i++)
			dp[i][i] = 0;
		for (size_t i = len-2; i >=0; i--) //从次上对角线开始
		{
			for (size_t j = i+1; j < len; j++)
			{
				if (s[i] == s[j]) {
					if (j - i == 1)
						dp[i][j] = 2;
					else
						dp[i][j] == dp[i + 1][j - 1] + 2;
					//向对角线方向移动
					//它只能寻找最大的回文子串
					//回文子串短于2就会出错
					if (max_len < dp[i][j])
					{
						max_len = dp[i][j];
						start_index = i;
					}
				}
				else
					dp[i][j] = 0;

			}

		}
		//cout << "max len is " << max_len << endl;
		//cout << "star index is" << start_index << endl;
		return max_len;
	}

};

longest::longest()
{
}

longest::~longest()
{
}
string vec2str(vector<int> v) {
	stringstream ss;
	for (size_t i = 0; i < v.size(); i++)
		ss << v[i];
	return ss.str();
}

vector<int> getnext(vector<int>& v) {
	int count = 1;
	int num = v[0];
	vector<int> seq;
	for (size_t i = 1; i < v.size(); i++)//start from 1
	{
		if (v[i] == num)
			count++;
		else {
			
			seq.push_back(count);
			seq.push_back(num);
			num = v[i];
			count = 1;
		}
	}
	seq.push_back(count);
	seq.push_back(num);

	return seq;
}

string countandsay(int n) {
	if (n == 0)  return "";
	if (n == 1) return"1";
	string s;
	vector<int> v;
	v.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		v = getnext(v);
	}
	s = vec2str(v);
	return s;
}
int main(int argc,char** argv)
{
	int n = 4;
	if (argc>1)
	{
		n = atoi(argv[1]);
	}
	cout << countandsay(n) << endl;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
