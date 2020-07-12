#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
     public:
	/*
	 *   The easy solution is O(n^2) run-time complexity.
	 *   ```
	 *       foreach(item1 in array) {
	 *           foreach(item2 in array){
	 *               if (item1 + item2 == target) {
	 *                   return result
	 *               }
	 *           }
	 *   ```
	 *
	 *   We can see the nested loop just for searching,
	 *   So, we can use a hashmap to reduce the searching time complexity from O(n) to O(1)
	 *   (the map's `key` is the number, the `value` is the position)
	 *
	 *   But be careful, if there are duplication numbers in array,
	 *   how the map store the positions for all of same numbers?
	 *
	 */
		
	 // The implementation as below is bit tricky. but not difficult to understand
	 //
	 //  1) Traverse the array one by one
	 //  2) just put the `target - num[i]`(not `num[i]`) into the map
	 //     so, when we checking the next num[i], if we found it is exisited in the map.
	 //     which means we found the second one.
	//    
	//vector<int> twoSum(vector<int> &numbers, int target) {
	// unordered_map<int, int> m;
	// vector<int> result;
	// for (int i = 0; i < numbers.size(); i++) {
	//	 // not found the second one
	//	 if (m.find(numbers[i]) == m.end()) {
	//		 // store the first one poisition into the second one's key
	//		 m[target - numbers[i]] = i;
	//	 }
	//	 else {
	//		 // found the second one
	//		 result.push_back(m[numbers[i]] + 1);
	//		 result.push_back(i + 1);
	//		 break;
	//	 }
	// }
	// return result;
	//}


     // we can store nums[i] into map, and find target - nums[i]
	 vector<int> twoSum(vector<int>& nums, int target) {
		 unordered_map<int, int> m;
		 vector<int> result;
		 for (int i = 0; i < nums.size(); i++) {
			 if (m.find(target - nums[i]) == m.end()) {
				 m[nums[i]] = i;
			 }
             else {
			       result.push_back(m[target - nums[i]]);
			       result.push_back(i);
			 }
		 }
			return result;
	 }

	 vector<vector<int>> Sumthree(vector<int>& nums, int target ) {
		 vector<vector<int>> result;
		 if (nums.size() <= 3) return result;
		 
		 sort(nums.begin(), nums.end());
		 for (auto i = nums.begin(); i < nums.end() - 2; i++) {
			 if( i != nums.begin()&&*(i-1)==*i) continue;
			 auto j = i + 1, k = nums.end() - 1;
			 while (j<k)
			 {
				 int sum = *i + *j + *k;
				 if (sum == target)
				 {
					 vector<int> trinumsum2zero = { (int)(i - nums.begin()),(int)(j - nums.begin()),int(k - nums.begin()) };
					 //trinumsum2zero.insert(trinumsum2zero.begin(), 2);//confusing
					 result.push_back(trinumsum2zero);
					 j++;
					 k--;
				 }
				 else if (sum > target){
					 if (k > nums.begin() && *(k - 1) == *k)
						 k--;
					 k--;
				 }
					
				 else if (sum < target) {
					 if (j < nums.end() - 2 && *j == *(j + 1))
						 j++;
					 j++;
				 }		
			 }

		 }
		 return result;
	 }

	 vector <vector<int>> sum4(vector<int> n, int target) {
		 vector <vector<int>> result;
		 if (n.size() < 4)
			 return result;
		 vector <vector<int>>  sum3result;
		 sort(n.begin(), n.end());

		 for (size_t i = 0; i < n.size()-3; i++)
		 {
			 if (i > 0 && n[i - 1] == n[i])
				 continue;
			 vector <int> numafter(n.begin() + i + 1, n.end());

			 sum3result = Sumthree(numafter, target - n[i]);

			 if (sum3result.size()!=0)
			 {
				 for (auto sum3item : sum3result)
				 {
					 sum3item.insert(sum3item.begin(), n[i]);
					 result.push_back(sum3item);
				 }
			 }

		 }
		 return result;
	 }
};

int  main() {

	vector<int> result;
	Solution a;
	vector <int> b = { -1,1,0,2 };
	result = a.twoSum(b, 0);
	//char s[10];
	//printf("%s", s);
	return 0;
}