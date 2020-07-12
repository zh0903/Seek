#include <opencv2/opencv.hpp>
#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

int atoii( char* s,const int &len) {

	if (s == NULL)
		return -1;
	int i = 1;
	int sum = 0;
	for (int j = len-1; j>=0 ;j-- ) {
		if (*(s + j) <= '9'&&*(s + j) >= '0') {
			sum += (*(s + j) - '0')*i;
			i *= 10;
		}
		else
		{
			cout << "input must be numbers" << endl;
			return -1;
		}
	}
	return sum;
}
int main()
{
	char s[10] = "10086";
	int n = strlen(s);
	int sum=0;
	sum = atoii(s, n);
	cout<< sum<<endl;
}


