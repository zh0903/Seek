#include"stdafx.h"
//ȫ��������
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
//������n���ַ�Ҫ���У����������ηŵ�n��������
//��Ҫ��������Ƿ�Ϊ�գ����л���ʲô�ַ��������ǷŽ�����ǡ�
//����һ��Ҫ�ָ���ʼ״̬������n+1������ʱ��һ�������Ѿ�����
void dfs(int step)
{
	int i;
	if (step == n + 1)//�жϱ߽�
	{
		for (i = 1; i <= n; i++)
			printf("%c", re[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= n; i++)//����ÿһ�����
	{
		if (vis[i] == 0)//check����
		{
			re[step] = a[i];
			vis[i] = 1;//���
			dfs(step + 1);//��������
			vis[i] = 0;//�ָ���ʼ״̬
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
		memset(vis, 0, sizeof(vis));//�Դ����ݵ�����ֱ��ʼ��
		scanf_s("%s", a + 1);
		n = strlen(a + 1);
		dfs(1);//�ӵ�һ�����ӿ�ʼ
	}
	getchar();
	getchar();
	return 0;
}