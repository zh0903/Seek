#include"stdafx.h"
//全排列问题
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;
int n;
char  a[15];
char re[15];
int vis[15];

//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array)
//	{
//		if (array.size() == 0)
//			return false;
//		for (int i = 0; i < array.size(); i++)
//		{
//			for (int j = array[0].size() - 1; j >= 0; j--)
//			{
//				if (target > array[i][j])
//				{
//					i++;
//					break;
//				}
//				if (target == array[i][j])
//					return true;
//				else
//					continue;
//			}
//		   }
//				return false;
//		}
//	};
//假设有n个字符要排列，把他们依次放到n个箱子中
//先要检查箱子是否为空，手中还有什么字符，把他们放进并标记。
//放完一次要恢复初始状态，当到n+1个箱子时，一次排列已经结束
void dfs(int step)
{
	int i;
	if (step == n + 1)//判断边界
	{
		for (i = 1; i <= n; i++)
			printf("%c", re[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= n; i++)//遍历每一种情况
	{
		if (vis[i] == 0)//check满足
		{
			re[step] = a[i];
			vis[i] = 1;//标记
			dfs(step + 1);//继续搜索
			vis[i] = 0;//恢复初始状态
		}
	}
	return;
}

int main(void)
{
	int T;
	scanf_s("%d", &T);
	getchar();
	while (T--)
	{
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));//对存数据的数组分别初始化
		scanf_s("%s", a + 1);
		n = strlen(a + 1);
		dfs(1);//从第一个箱子开始
	}
	getchar();
	getchar();
	return 0;
}