// longestSTRwithoutRep.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>
#include <map>
using namespace std;
int findlongest(string s) {
	map<char, int> m;   // 1st是key 不能重复
	int maxlen = 1;
	int lastRepeatPos = -1;
	for (int i = 0; i < s.size(); i++)
	{
		if (m.find(s[i])!=m.end()&&lastRepeatPos<m[ s[i] ])
	//第二个条件保证“abcaba”这样的前面的a计长度不会影响后面从a开始的计数
		{
			lastRepeatPos = m[s[i]];
		}
		if (i - lastRepeatPos > maxlen) {
			maxlen = i - lastRepeatPos;
		}
		m[s[i]] = i;
	}
	return maxlen;

}
//don't use <map>
int lengthOfLongestSubstring(string s) {
	const int MAX_CHARS = 256;
	int m[MAX_CHARS];
	memset(m, -1, sizeof(m));
	//void *memset(void *s, int ch, size_t n);
	//函数解释：将s中当前位置后面的n个字节 
	//（typedef unsigned int size_t ）用 ch 替换并返回 s 。
	//memset：作用是在一段内存块中填充某个给定的值，
	//	它是对较大的结构体或数组进行清零操作的一种最快方法

	int maxLen = 0;
	int lastRepeatPos = -1;
	for (int i = 0; i < s.size(); i++) {
		if (m[s[i]] != -1 && lastRepeatPos < m[s[i]]) {
			lastRepeatPos = m[s[i]];
		}
		if (i - lastRepeatPos > maxLen) {
			maxLen = i - lastRepeatPos;
		}
		m[s[i]] = i;
	}
	return maxLen;
}
int main(int argc, char** argv)
{
	string s = "abcabcbb";
	cout << s << " : " << lengthOfLongestSubstring(s) << endl;

	s = "bbbbb";
	cout << s << " : " << lengthOfLongestSubstring(s) << endl;

	s = "bbabcdb";
	cout << s << " : " << lengthOfLongestSubstring(s) << endl;

	if (argc > 1) {
		s = argv[1];
		cout << s << " : " << lengthOfLongestSubstring(s) << endl;
	}

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
