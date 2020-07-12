#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* insertSort(ListNode* head)
{
	//Void judgment
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode *pSorted = NULL;

	while (head != NULL)
	{
		ListNode *remhead = head;
		ListNode **pptrail = &pSorted;
		
		/* pop head off list */
		head = head->next;
	}
}