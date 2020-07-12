// sortt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;


template<class T>
int partition(T raw[],int len) {
	int low = 0, high = len - 1;
	int pole = raw[low];
	while (low<high)
	{
		while (low<high&&raw[low]<=pole)
		{
			low++;
		}
		raw[high] = raw[low];

		while (high>low&&raw[high]>=pole)
		{
			high--;
		}
		raw[low] = raw[high];
	}
	raw[low] = pole;
	return low;
}

void  merge(int a[], int m, int b[], int n) {
	int im = m - 1;
	int in = n - 1;//two ascending
	for (size_t i = m+n-1; i >=0; i--)
	{
		if (im >= 0 && in >= 0) {
			a[i] = (a[im] >= b[in]) ? a[im--] : b[in--];
			//only one Expression will be calculate
		}
		if (im >= 0 && in < 0)
			break;
		if (im < 0 && in >= 0)
			a[i] = b[in--];
	}
}
void qsort(int raw[], int low ,int high) {//传递两个游标确认递归终止条件
	int point;
	while (low < high) {
		point = partition(raw, high - low + 1);
		qsort(raw, low, point - 1);
		low = point + 1;				//尾递归
	}
}

void insertsort(vector<int> &raw, int n) {
	if (n == 0) 
		cout<<"empty array"<<endl;
	else if (n == 1)
		return;
	int temp;
	for (size_t i = 1; i < n; i++)
	{
		if (raw[i] < raw[i - 1]) {
			temp = raw[i];
			for (size_t j = i-1; temp<raw[j]; j--)
			{
				raw[j + 1] = raw[j];
			}
			raw[j+1] = temp;
		}
	}
}

void shellsort(vector<int>& raw, int n) {
	if (n == 0)
		cout << "empty array" << endl;
	else if (n == 1)
		return;

	int gap = n;
	int temp;
	int i, j;
	do
	{
		gap = gap / 3 + 1;   // for(int delta = ed - st; delta; delta /= 2)
		for ( i = gap; i < n; i++)
		{
			if (raw[i] < raw[i - gap]) {
				temp = raw[i];
				for ( j = i - gap; temp < raw[j]; j-=gap)
				{
					raw[j + gap] = raw[j];
				}
				raw[j + gap] = temp;
			}
		}
	} while (gap>1);

}

void heapAdjust(vector<int> &raw,int start,int len) {
	int temp = raw[start];
	for (size_t i =2*start+1; i < len; i*=2)
	{
		if (i + 1 < len&&raw[i + 1] > raw[i]) {
			i += 1;
		}
		raw[start] = raw[i];
		start = i;
	}
	raw[start] = temp;
}

void swap(vector<int> &arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void heapsort(vector<int>& raw, int n) {
	for (size_t i = n/2-1; i >=0; i--)
	{
		heapAdjust(raw, i, n);
	}
	
	for (size_t j = n-1; j >0; j--)
	{
		swap(raw, 0, j);
		heapAdjust(raw, 0, j);
	}
    
}
void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int*a, int*b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void colorSort(int a[], int n) {
	int zero = 0,two=n-1;
	for (size_t i = 0; i < n-1; i++)
	{
		if (a[i]==0)
		{
			swap(&a[zero], &a[i]);
			zero++;
		}
		else if (a[i]==2)
		{
			swap(&a[two], &a[i]);
			i--;
			two--;
		}
	}
}
int main()
{
	int n = 7;
	srand(time(NULL));
	int *a = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		*(a + i) = rand()% 3;
	}
	printArray(a, n);
	colorSort(a, n);
	printArray(a, n);
	delete []a ;
	return 0;
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
	ListNode fake(0);
	fake.next = head;
	head = &fake;

	ListNode* pos = NULL;
	for (ListNode* i = head; i!=NULL&&i->next!=NULL; i++)
	{
		if (pos==NULL&&i->next->val>=x)
		{
			pos = i;
			i = i->next;
			continue;
		}
		if (pos!=NULL&&i->next->val<x)
		{
			ListNode * inext= i->next;
			i->next = inext->next;
			inext->next = pos->next;//move node less than x to the next of pos.
			pos->next = inext;
			pos = inext;
			continue;
		}

		i = i->next;
	}


	return head->next;
}

void printList(ListNode* h)
{
	while (h != NULL) {
		printf("%d ", h->val);
		h = h->next;
	}
	printf("\n");
}

ListNode* createList(int a[], int n)
{
	ListNode *head = NULL, *p = NULL;
	for (int i = 0; i < n; i++) {
		if (head == NULL) {
			head = p = new ListNode(a[i]);
		}
		else {
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}
