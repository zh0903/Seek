//// stringg.cpp : 定义控制台应用程序的入口点。
////
//
//#include "stdafx.h"
//#include <string>
//using namespace std;
//
//int* getNext(string p) {
//	int* next = new int[p.length()];
//	int j=0, k=-1;
//	next[0] = -1;
//	while(j < (int)p.length() - 1)
//	{
//		if (k == -1 || p[j] == p[k])
//		{
//			if(p[++k]=p[++j])
//			    next[j] = next[k];
//			else
//			{
//				++j;
//				++k;
//				next[j] = k;
//			}
//		}
//		else
//		{
//			k = next[k];
//		}
//		
//	}
//	return next;
//}
//
//int KMP(string T, string p) {
//	int * next = getNext(p);
//	int j = 0, k = 0;
//	while (p[k]&&T[j]) //break if number equal to length, not lenth-1.
//	{
//		if (k==-1||T[j] == p[k]) 
//		{
//			j++;
//			k++;  
//		}
//		else
//		{
//			k = next[k];
//		}
//
//	}
//	if (k == p.length())
//		return j - k;
//	else
//		return -1;
//}
//
//int main()
//{
//    return 0;
//}
//