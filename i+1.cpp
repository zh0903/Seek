#include "pch.h"
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <opencv2/opencv.hpp>
using namespace std;

#define INTMAX     2147483647
#define INTMIN     (-INTMAX - 1)

int divide(int dividend, int divisor) {

	int sign = (float)dividend / divisor > 0 ? 1 : -1;

	unsigned int dvd = dividend > 0 ? dividend : -dividend;
	unsigned int dvs = divisor > 0 ? divisor : -divisor;

	unsigned int bit_num[33];
	unsigned int i = 0;
	long long d = dvs;
	bit_num[i] = d;
	while (d <= dvd) {
		bit_num[++i] = d = d << 1;//----
	}							  //	|
	i--;						  //	| 	
								//		|
	unsigned int result = 0;    //      | 
	while (dvd >= dvs) {		//		|	
		if (dvd >= bit_num[i]) {//		|
			dvd -= bit_num[i];	//		|
								//		|	
			result += (1 << i);  //-----
			cout << result << endl;
		}
		else {
			i--;
		}
	}

	//becasue need to return `int`, so we need to check it is overflowed or not.
	if (result > INT_MAX && sign > 0) {
		return INT_MAX;
	}
	return (int)result * sign;
}


//void printArray(vector<int>& v) {
//	cout << "{";
//	for (int i = 0; i < v.size(); i++) {
//		cout << " " << v[i];
//	}
//	cout << " }" << endl;
//}


void printResult(vector<vector<int> >& result)
{
	for (int i = 0; i < result.size(); i++) {
		cout << "{";
		for (int j = 0; j < result[i].size(); j++) {
			cout << " " << result[i][j];
		}
		cout << " }" << endl;
	}
}

vector<vector<int>> subSet(vector<int> & s) {
	
	vector<vector<int>> res(1);		 //需要初始化一个空一维向量
	sort(s.begin(), s.end());
	for (size_t i = 0; i < s.size(); i++)	{
		size_t size = res.size();
		for (size_t j = 0; j < size; j++)
		{
			res.push_back(res[j]);   //前j项
			res.back().push_back(s[i]);
		}
	}
	return res;
}

int main()
{
	//int a = 6;
	//std::cout << ~a<<endl;
	//a = -~a;//invert bitwise  ~a  in complement code  ~a will be convert to -1-a
	//std::cout << a;

	//cout << sizeof(long long)<<endl;

	//cout << "10/3=" << divide(200,8) << endl;
	/*  int i = 0 << 1;  gray code
	cout << (1>>1) << endl;*/
	//int s = 128;
	//cout << bitset<sizeof(s) * 8>(s)<<endl;
	int n[] = { 1, 2, 3, 4};
	vector<int> v(n, n + 4);

	vector<vector<int> > r = subSet(v);
	printResult(r);

	return 0;
}
