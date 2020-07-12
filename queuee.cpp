
#include "stdafx.h"
#include <deque>
#include <vector>
using namespace std;

class minoqueue
{
public:
	void push(int x) {
		while (!data.empty()&&data.back()<x)
		{
			data.pop_back();
		}
		data.push_back(x);
	}

	int max() {
		return data.front();
	}

	void pop(int x) {
		if (!data.empty() && data.front == x)
			data.pop_front();
	}
private:
	deque<int> data;
};

minoqueue::minoqueue()
{
}

minoqueue::~minoqueue()
{
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	minoqueue window;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		if (i < k - 1) {          //���������ڵ�ǰ k - 1   ����k����k-1
			window.push(nums[i]);
		}
		else {
			window.push(nums[i]);
			result.push_back(window.max());
			window.pop(nums[i - k + 1]);
		}
	}
	return result;
}


class maxPriorityQueue
{
public:
	maxPriorityQueue();
	~maxPriorityQueue();
	void push(int e) {
		data.push_back(e);
		swim(data.size());
	}

	int max() {
		return data[1];
	}

	int delMax() {
		// ���ѵĶѶ��������Ԫ��
		int max = data[1];
		// ��������Ԫ�ػ������ɾ��֮
		exch(data[1],data[data.size()]);
		data.pop_back();
		// �� pq[1] �³�����ȷλ��
		sink(1);
		return max;
	}

	// ���ڵ������
	int parent(int root) {
		return root / 2;
	}
	// ���ӵ�����
	int left(int root) {
		return root * 2;
	}
	// �Һ��ӵ�����
	int right(int root) {
		return root * 2 + 1;
	}

	void swim(int k) 
	{
		while (k>1&&data[k]>data[parent(k)])
		{
			exch(data[k], data[parent(k)]);
			k = parent(k);
		}
	}
	void sink(int k) 
	{
		while (k<data.size())
		{
			if (right(k) < data.size() && data[right(k)] > data[k])
			{
				exch(data[k], data[right(k)]);
				k = right(k);
			}
			if (data[k] < data[left(k)])
			{
				exch(data[k], data[left(k)]);
				k = left(k);
			}
			else
			{
				break;
			}
		}
	}

	void exch(int i, int j) {
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
private:
	vector<int> data;
};

maxPriorityQueue::maxPriorityQueue()
{
	data = vector<int>(0);
	data.push_back(-1);
}

maxPriorityQueue::~maxPriorityQueue()
{
}
int main()
{
    return 0;
}

