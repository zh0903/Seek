// LRU.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


int main()
{
	LRU<int,int> s(2);
	s.set(2, 1);
	s.set(1, 1);
	cout << s.get(2) << endl;
	s.set(4, 1);
	s.set(5, 2);
	cout << s.get(5) << endl;
	cout << s.get(4) << endl;
	getchar();
	return 0;
		
}


