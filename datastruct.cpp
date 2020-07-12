// datastruct.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
using namespace std;

//线索二叉树
enum pointerTag
{
	link,
	thread
};
struct biThrNode {
	char data;
	struct biThrNode * lc, *rc;
	pointerTag ltag;
	pointerTag rtag;
	biThrNode(char c) :data(c),lc(NULL),rc(NULL){
		ltag = lc ? link : thread;
		rtag = rc ? link : thread;
	}
};

void creat(biThrNode ** t) {
	char c;
	cin >> c;
	if (' '==c)
		*t = NULL;
	else
	{
		*t = new biThrNode(c);
		(*t)->ltag = link;
		(*t)->rtag = link;
	
		creat(&((*t)->lc));
		creat(&((*t)->lc));
	}
}
void threading(biThrNode* t) {

	if (t) {
		biThrNode* pre = new biThrNode('0');
		threading(t->lc);
		if (!(t->lc))//没左孩子指向记录节点
		{
			t->ltag = thread;
			t->lc = pre;
		}
		if (!pre->rc) //if there is mutual relationship? 
		{
			pre->rtag = thread;
			pre->lc = t;
		}
		pre = t;

		threading(t->rc);
}
}


int main()
{
	biThrNode* t = NULL;
	creat(&t); 
	
	return 0;
}

