#include<string>
#include<iostream>

void replaceSpace(char *str, int length) {
	
	if (str == NULL || length<0)
		return;
	int i;
	int oldnumber = 0;//记录以前的长度
	int replacenumber = 0;//记录空格的数量
	while (str[i] != '\0')
	{
		oldnumber++;
		if (str[i] == ' ')
		{
			replacenumber++;
		}
		i++;
	}
	int newlength = oldnumber + replacenumber * 2;//插入后的长度
	if (newlength>length)//如果计算后的长度大于总长度就无法插入
		return;
	int pOldlength = oldnumber; //注意不要减一因为隐藏个‘\0’也要算里
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