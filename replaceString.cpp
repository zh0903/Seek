#include<string>
#include<iostream>

void replaceSpace(char *str, int length) {
	
	if (str == NULL || length<0)
		return;
	int i;
	int oldnumber = 0;//��¼��ǰ�ĳ���
	int replacenumber = 0;//��¼�ո������
	while (str[i] != '\0')
	{
		oldnumber++;
		if (str[i] == ' ')
		{
			replacenumber++;
		}
		i++;
	}
	int newlength = oldnumber + replacenumber * 2;//�����ĳ���
	if (newlength>length)//��������ĳ��ȴ����ܳ��Ⱦ��޷�����
		return;
	int pOldlength = oldnumber; //ע�ⲻҪ��һ��Ϊ���ظ���\0��ҲҪ����
	int pNewlength = newlength;

	while (pOldlength >= 0 && pOldlength < newlength)
	{
		if (str[pOldlength] != ' ')
		{
			str[newlength--] = str[pOldlength--];
		}
		else
		{
			str[newlength--] = '0';
			str[newlength--] = '2';
			str[newlength--] = '%';
			pOldlength--;
		}
	}

}
int main()
{

	return 0;
}