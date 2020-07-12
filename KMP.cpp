#include "cstdio"
#include "iostream"
#include "cstring"
using namespace std;

int ne[20];///���������ʢ�ŵ���ƥ���ַ�����nextֵ
void GetNext(char *a)///���������Ϊ�˱��ƥ���ַ�����nextֵ
{
	int len = strlen(a);///�����ַ����ĳ��ȣ�����ѭ����ֵ
	int i = 0, j = -1;
	ne[0] = -1;
	while (i < len)
	{
		if (j == -1 || a[i] == a[j])
		{
			++i;
			++j;
			if (a[i]!=a[j])
			{
				ne[i] = j;
			}
			else
			{
				ne[i] = ne[j];
			}
			
		}
		else j = ne[j];
	}
}
///ʵ����ÿ��һ��nextֵҪѭ������
int KMP(char *a, char *b)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int i = 0, j = 0;
	while (i < lena && j < lenb)
	{
		if (j == -1 || a[i] == b[j])
		{
			j++;
			i++;
		}
		else
			j = ne[j];
	}
	if (j == lenb)
		return i - j + 1;
	else
		return -1;
}

int main()
{
	char s[100];///this is the main
	char f[100];///this is the one to be found
	scanf("%s", &s);
	scanf("%s", &f);
	GetNext(f);
	cout << KMP(s, f) << endl;

	return 0;
}