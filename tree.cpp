// tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
enum balancefactor
{
	LEFTHIGH,
	EQUAL,
	RIGHTHIGH
};
struct balanceTreeNode{
	int data;
	balancefactor bf;
	balanceTreeNode* lc, *rc;
};
void RR(balanceTreeNode** p) {
	balanceTreeNode* pleftright;
	pleftright = (*p)->lc;
	(*p)->lc = pleftright->rc;
	 *p = pleftright;

	  //       *
	 //      *
	//     *   *
}

void leftBalance(balanceTreeNode ** T) {
	balanceTreeNode * L=(*T)->lc, *LR;
	if (L->bf==LEFTHIGH)
	{
		(*T)->bf = L->bf = EQUAL;
		RR(T);
	}
	else
	{
		LR = L->rc;
		switch (LR->bf)
		{
		case EQUAL:
			(*T)->bf = L->bf = EQUAL;
			break;
		case LEFTHIGH:  //想想那种情况会出现t-l-lr->bf
			(*T)->bf = RIGHTHIGH;
			L->bf = EQUAL;
			break;
		case RIGHTHIGH:
			(*T)->bf = EQUAL;
			L->bf = LEFTHIGH;
			break;
			 
		default:
			break;
		}
		LR->bf = EQUAL;
		LR(&(*T)->lc);
		RR(T);

	}

}
void LR(balanceTreeNode** p) {
	balanceTreeNode* prightleft;
	prightleft = (*p)->rc;
	(*p)->rc=prightleft->lc;
	*p = prightleft;
}
bool inserted(balanceTreeNode ** T,int data){
	if (*T == NULL)
	{
		*T = new balanceTreeNode ;   
		(*T)->data = data;			
		(*T)->lc = (*T)->rc = NULL;
		(*T)->bf = EQUAL;
		return true;
		//delete  T;
	}
	else
	{
		if (data==(*T)->data)
			return false;				
		else if (data <= (*T)->data)
		{
			if (inserted(&((*T)->lc), data) == false)
				return false;
			else {
				switch ((*T)->bf)
				{
					case LEFTHIGH:
							leftBalance(T);
							return false;
					case EQUAL:
							(*T)->bf = LEFTHIGH;
							return true;
					case RIGHTHIGH:
							(*T)->bf = EQUAL;
							return false;
					default:
						break;
				}
			}

		}
		else
		{
			if (inserted(&(*T)->rc,data)==false)
					return false;
			//child tree does not grow after inserting
			
			else {
			switch ((*T)->bf)
				{
				case LEFTHIGH:
					(*T)->bf = EQUAL;
					return false;
				case EQUAL:
					(*T)->bf = RIGHTHIGH;
					return true;
				case RIGHTHIGH:
					RightBalance(T);
					return false;
				}
			}
		}
	}
}
int main()
{
    return 1; 
}
