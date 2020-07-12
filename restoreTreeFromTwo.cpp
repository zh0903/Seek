#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution{
public:
	TreeNode * buildtree(vector<int>& pre, vector<int>& in)
	{
		if (pre.size() == 0) return NULL;
		TreeNode* root = new TreeNode(pre[0]);
		if (pre.size() == 1) return root;

		vector<int> leftIn, leftPre, rightIn, rightPre;
		int location = 0;
		while (in[location]!=pre[0])//pre0 is the rootnode
		{
			leftIn.push_back(in[location]);
			++location;
		}
		for (size_t i = 1; i < location; ++i)
		{
			leftPre.push_back(pre[i]);
		}
		for (int i = location + 1; i<pre.size(); i++) {
			rightPre.push_back(pre[i]);
			rightIn.push_back(in[i]);
		}
		root->left = buildChild(leftPre, leftIn);
		root->right = buildChild(rightPre, rightIn);
		return root;
	}


	TreeNode* buildChild(vector<int> preorder, vector<int> inorder)
	{
		if (preorder.size() == 0) return NULL;          //出口条件:preorder为空，则表示这个节点是NULL
		TreeNode* root = new TreeNode(preorder[0]);  //生成当前子树的根节点
		vector<int> leftIn, leftPre, rightIn, rightPre;
		int location=0;
		while (inorder[location] != root->val) {
			leftIn.push_back(inorder[location]);
			location++;
		}
		for (int i = 1; i <= location; i++) leftPre.push_back(preorder[i]);
		for (int i = location + 1; i<preorder.size(); i++) {
			rightPre.push_back(preorder[i]);
			rightIn.push_back(inorder[i]);
		}
		root->left = buildChild(leftPre, leftIn);
		root->right = buildChild(rightPre, rightIn);
		return root;
	}
};
