#include<bits/stdc++.h>
using namespace std;

class AscentSequence {
public:
	int findLongest(vector<int> A, int n) {
		// write code here
		vector<int> arr;
		for (int i = 0; i < n; i++)
			//�����������arrΪ��,���ߵ�ǰԪ�رȸ�������ĩβԪ�ش�,�͸��¸�������ĩβԪ��
			if (arr.size() == 0 || arr.back() < A[i])
				arr.push_back(A[i]);
			else
			{
				int low = 0, high = arr.size() - 1;
				while (low < high) //���ֲ��Ҹ��������е�һ�����ڵ���A[i]����,�����滻
				{
					int mid = (low + high) / 2;
					if (arr[mid] < A[i])
						low = mid + 1;
					else
						high = mid;//���ַ����� ע�⣡
				}
				arr[low] = A[i];
			}
		//�������鳤�ȼ�Ϊ����������еĳ���
		return arr.size();
	}
};


// �����������������������м��Խ���������е� 
#include<iostream>
#include<algorithm>
using namespace std;

int *arr;
int *dp;

// �������� dp[i]����˼Ϊ��iΪ��β���������Ϊ���� 
int getResult(int n) {
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {  // ��֤���� 
				cnt = max(cnt, dp[j] + 1);
			}
		}
		dp[i] = cnt;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	return ans;
}
//_______ʱ�临�Ӷ�Nƽ��

// ���ֲ��ұ��� �ҵ���һ������n��λ��index 
int BinarySearch(int *dp, int len, int n) {
	int left = 1,right = len;
	while (left < right) {
		int mid = (left + right) / 2;
		if (dp[mid] > n) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}

// �Ż���dp dp����������±�Ϊ�� 
int getResult1(int n) {
	dp[1] = arr[0];
	int index = 1;
	for (int i = 1; i < n; i++) {

		if (arr[i] > dp[index]) {			
			dp[++index] = arr[i];// ����index 
		}

		else {// ��dp�����е�һ������n�������滻Ϊarr[i] 
			int tempIndex = BinarySearch(dp, index, arr[i]);
			dp[tempIndex] = arr[i];
		}
	}
	return index;
}

int main() {
	int n;
	while (cin >> n) {
		arr = new int[n];
		dp = new int[n + 1];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int ans = getResult1(n);
		cout << ans << endl;
		delete[] arr;
		delete[] dp;
	}
	return 0;
}
