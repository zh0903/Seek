#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
int month[14] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };

bool isLeapyear(const int y)
{
	if (y%400==0) return true;
	if (y % 4 == 0 && y % 100 != 0) return true;

	return false;
}

/*inline*/ void countMonthday(int startmonth, int endmonth,int& days)
{
	for (size_t i = startmonth; i < endmonth; i++)
	{
		days += month[i];
	}
    
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> start(3,0);
	auto end = vector<int>(3,0);
	char temp;
	int weekdayGiven;

	for (size_t i = 0; i < 3; i++)
	{
		cin >> start[i];
	}
	cin >> weekdayGiven;
	cin >> temp;
	for (size_t i = 0; i < 3; i++)
	{
		cin >> end[i];
	}
	bool swapflag=false;
	if (((start[0] - end[0]) * 356 + (start[1] - end[1]) * 30 + (start[0] - end[0])) > 0)
	{
		swapflag = true;
		vector<int> temp = start;
		start = end;
		end = temp;
	}


	int days = 0;

	bool firflag = isLeapyear(start[0]);
	bool secflag = isLeapyear(end[0]);

	if (start[0] == end[0])  //same year
	{
		if (start[1] == end[1])
		{//fir和sec在同一个月
			days += end[2] - start[2];
		}
		else 
		{
			days += month[start[1]] - start[2];
			countMonthday(start[1] + 1, end[1], days);
			days += end[2];
			if (firflag && start[1] <= 2 && end[1]>2) days += 1; //处理闰年
		}
	}

	else   //not same year
	{
		days += month[start[1]] - start[2];
		countMonthday(start[1] + 1, 12, days);
		countMonthday(1, end[1], days);
		days += end[2];
		if (firflag&&start[1] < 2) days += 1;
		if (secflag && end[1] > 2) days += 1;
	}
	int ans=0;
	ans = swapflag ? (weekdayGiven - (days % 7) + 7) % 7:((weekdayGiven+(days%7))%7);
	cout << ans << endl;
	system("pause");
	return 0;
}
