#include<bits/stdc++.h>
using namespace std;

class AscentSequence {
public:
	int findLongest(vector<int> A, int n) {
		// write code here
		vector<int> arr;
		for (int i = 0; i < n; i++)
			//如果辅助数组arr为空,或者当前元素比辅助数组末尾元素大,就更新辅助数组末尾元素
			if (arr.size() == 0 || arr.back() < A[i])
				arr.push_back(A[i]);
			else
			{
				int low = 0, high = arr.size() - 1;
				while (low < high) //二分查找辅助数组中第一个大于等于A[i]的数,进行替换
				{
					int mid = (low + high) / 2;
					if (arr[mid] < A[i])
						low = mid + 1;
					else
						high = mid;//二分法变体 注意！
				}
				arr[low] = A[i];
			}
		//辅助数组长度即为最长递增子序列的长度
		return arr.size();
	}
};


// 这里的最长递增子序列是允许中间跨越其他子序列的 
#include<iostream>
#include<algorithm>
using namespace std;

int *arr;
int *dp;

// 经典问题 dp[i]的意思为以i为结尾的最长子序列为多少 
int getResult(int n) {
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {  // 保证递增 
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
//_______时间复杂度N平方

// 二分查找变体 找到第一个大于n的位置index 
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

// 优化的dp dp数组的最终下标为答案 
int getResult1(int n) {
	dp[1] = arr[0];
	int index = 1;
	for (int i = 1; i < n; i++) {

		if (arr[i] > dp[index]) {			
			dp[++index] = arr[i];// 更新index 
		}

		else {// 把dp数组中第一个大于n的数字替换为arr[i] 
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
