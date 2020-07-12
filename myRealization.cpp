// myRealization.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;
 
class string
{ 
	public:

		string(const char *str) {
			if (str == NULL)
			{
				char a[1] = { '\0' };
				mydate = a;
			}
			else
			{
				mydate = new char[strlen(str) + 1];
				strcpy(mydate, str);
			}
		}

		~string() {
			delete[] mydate;
		}

	    string(const string & str) {
			mydate = new char[strlen(str.mydate) + 1];
			strcpy(mydate, str.mydate);
		}

		string& operator=(const string& str) {
			if (this == &str)
				return *this;
			delete[] mydate;
			mydate = new char[strlen(str.mydate) + 1];
			strcpy(mydate, str.mydate);
			return *this;

		}

	private:
		char*	mydate;

};

class isnum
{
public:

	bool isdig(const char c) {
		return(c >= '0'&&c <= '9');
	}
	bool isspa(const char c) {
		return(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
	}
	bool isNumber(const char* s) {
		bool e=false;
		bool point=false;
		if (isspa(*s))
			s++;
	
		if (*s == '\0') 
			return false;

		if (*s == '+' || *s == '-') s++;

		for (;s!='\0';s++)
		{
			if (*s=='.')
			{
				if (point || e)
					return false;
				if (!isdig(*(s + 1)))
					return false;
				point = true;
				continue;
			}
			if (*s=='e')
			{
				if (point || e)
					return false;
				s++;
				if (*s == '+' || *s == '-') 
					s++;
				if (!isdig(*s))
					return false;
				e = true;
				continue;
			}
			while (isspa(*s))
				s++;
			if (s != '\0')
				return false;
			if (!isdig(*s))
				return false;
		}
		return true;
	}
};


int main()
{
	const char* s = "2e7";
	std::cout << "Hello World!\n";
	isnum test;
	cout << s << ":" << test.isNumber(s) << endl;
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
