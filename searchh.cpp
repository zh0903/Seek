#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/**********************************************************************************
*
* Given a sorted array of integers, find the starting and ending position of a given target value.
*
* Your algorithm's runtime complexity must be in the order of O(log n).
*
* If the target is not found in the array, return [-1, -1].
*
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
*
*
**********************************************************************************/

// because it is a sorted array, the duplicated target number must be continuous placed.
int binarysearch(int A[], int low, int high, int key) {
	
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == key)   return mid;
		else if (A[mid] < key)
			low = mid + 1;
		else if (A[mid] > key)
			high = mid - 1;		
	}
	return -1;
}

vector<int> searchRange(int A[],int len ,int target) {
	//int len = sizeof(A) / sizeof(A[0]);  Formal parameter A turn to be a pointer
	//cout << len << endl;
	if (len == 0)		
		return {-1,-1};	

	int low = -1, high = -1;
	int pos = binarysearch(A, 0, len - 1, target);
	if (pos>=0)   //judge greater than 0 may be easier for bit compare in hardware level
	{
		low = high = pos;	
		int l = low;
		do
		{
			low = l;
			l= binarysearch(A, 0, low - 1, target);
		} while (l>=0);

		int h = high;
		do {
			high = h;
			h = binarysearch(A, high + 1, len - 1, target);
		} while (h >= 0);
	}
	vector<int> v;
	v.push_back(low);
	v.push_back(high);
	return v;
}

void printVector(const vector<int>&  pt)
{
	cout << "{ ";
	for (int j = 0; j < pt.size(); j++) {
		cout << pt[j] << " ";
	}
	cout << "} " << endl;
}

int main()
{
	const int cnt = 6;
	int a[cnt] = { 5, 7, 7, 8, 8, 10 };

	vector<int> v;
	v = searchRange(a,sizeof(a)/sizeof(a[0]),8);
	printVector(v);
	return 0;
}

