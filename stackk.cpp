#include<bits/stdc++.h>
using namespace std;
class MinStack
{
private:
	struct minData
	{
		int min;
		int cnt;
		minData() :min(0), cnt(0) {}
		minData(int m, int c) :min(m), cnt(c) {}
	};
	stack<int> realstack;
	stack<minData> minStack;
	int min;
public:
	void push(int x)
	{
		if (realstack.empty()==true)
		{
			min = x;
			minStack.push(minData(x, 1));
		}
		else
		{
			if (min>=x)
			{
				min = x;
				if (minStack.top().min==x)
				{
					++minStack.top().cnt;
				}
				else
				{
					minStack.push(minData(x, 1));
				}
			}
		}
		realstack.push(x);
	}

	void pop()
	{
		if (realstack.empty()==true)
		{
			return;
		}
		int x = realstack.top();
		realstack.pop();
		if (x=minStack.top().min)
		{
			if (minStack.top().cnt > 1) 
			{
				minStack.top().cnt--;
			}
			else 
			{
				minStack.pop();
				min = minStack.top().min;
			}
		}
	}
	int top() {
		return realstack.top();
	}
	int getMin() {
		return min;
	}
	void clear() {
		while (realstack.empty()==false)
		{
			realstack.pop();
		}
		while (minStack.empty() == false);
		minStack.pop();
	}

};

int main()
{
	return 0;
}