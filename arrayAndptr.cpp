#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
//int sum( int(* ptr)[])
//{
//	unsigned int len = sizeof(&ptr) / sizeof(int);
//	printf("长度%d", len);
//	return 0;
//}
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int (*p)[4]= & a;
//	sum (p)
//}
//
//int arraySum(int arr[])
//{
//	
//
//	//unsigned int loop = 0;
//	/*循环前计算好长度，提高性能*/
//	//unsigned int len = sizeof(arr) / sizeof(int);
//	int sum = 0;
//	if (NULL == arr)
//	{
//		return 0;
//	}
//	for (int *p = arr; *p!=NULL;p++)//可怕
//	{
//		sum += *p;
//	}
//	return sum;
//}

class zigstr {
	/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
	*(you may want to display this pattern in a fixed font for better legibility)
		*
		* P   A   H   N
		* A P L S I I G
		* Y   I   R
		*
		* And then read line by line : "PAHNAPLSIIGYIR"
		*
		* Write the code that will take a string and make this conversion given a number of rows :
	*
		* string convert(string text, int nRows);
	*
		* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/
public:
	string zstr;
	int zrows;
	zigstr(string s,int rows):zstr(s),zrows(rows) {
	}
	string convert()
	{   
		//exceptional input 
		if (zrows <= 1 || zstr.size() < zrows)
		return zstr;

		vector<string> r(zrows);
		int row = 0;
	    int step = 1; //bool不可
		for (int i = 0; i < zstr.size();i++)
		{
			if (row == zrows - 1) 
				step = -1;
			if (row == 0) 
				step = 1;
			r[row] += zstr[i];
			row += step;
		}
		string result;
		for (int j = 0;j < zrows;j++)
			result += r[j];
			return result;
	}
};
int main(void)
{
	//int a[] = { 1,2,3,4,5,6 };
	//int sum = arraySum(a);
	//printf("arr sum is %d", sum);  
	//return 0;

	string s = "PAYPALISHIRING";
	zigstr a(s, 3);
	cout<<s<<':'<<a.convert()<<endl;
	return 0;
}



