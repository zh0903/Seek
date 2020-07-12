// character.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"//precompiledheader
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>
using namespace std;

class stringchar {
	string chars;
public: static string longestCommonPrefix(vector<stringchar> &strs) {
		string word;// private date member by default
		if (strs.size() <= 0) return word;
		for (int i = 1; i <= strs[0].chars.size(); i++) {
			string w = strs[0].chars.substr(0, i);
			bool match = true;
			
			for (int j = 1; j < strs.size(); j++) {
				if (i > strs[j].chars.size() || w != strs[j].chars.substr(0, i)) {
					match = false;
					break;
				}
			}
			if (!match) {
				return word;
			}
			word = w;//one more character was in common
		}
		return word;//str[0] is largest intersection
	}
	//char **s  equals to char *s[]
	stringchar(string s) :chars(s)
	{
	}
	static string bitadd(string a, string b) {
		int lena = a.size();
		int lenb = b.size();
		bool carry=false;
		string result;

		while (lena>0||lenb>0)
		{
			int abit = lena>0 ? (a[lena-1] - '0') : 0;
			int bbit = lenb>0 ? (b[lenb-1] - '0') : 0;
			int cbit = carry ? 1 : 0;
			result.insert(result.begin(), '0' + ((abit + bbit + cbit) & 1));
			lena--;
			lenb--;
			carry = (abit + bbit + cbit > 1);
		}
		if (carry)
			result.insert(result.begin(), '1');
		return result;

	}

	static int longestCommonSubstring(const string &lhp,const string &rhp) {
		if (lhp == "\0" || rhp == "\0")
			return 0;
		vector<vector<int>> opt(lhp.size(), vector<int>(rhp.size(), 0)) ;
		
		for (size_t i = 0; i < lhp.size(); i++)
		{  
			if (lhp[i] == rhp[0])
				opt[i][0] = 1;
		}
		for (size_t i = 0; i < rhp.size(); ++i) {
				if (rhp[0] == rhp[i])
				opt[0][i] = 1;
		}
		for (size_t i = 0; i < lhp.size(); i++)
		{
			for (size_t j = 0; j < rhp.size(); j++)
			{
				if (rhp[j])
				{
					opt[i][j] == opt[i - 1][j = 1] + 1;
				}
			}
		}
		int length;
		for (size_t i = 0; i < opt.size(); ++i) {
				for (size_t j = 0; j < opt[0].size(); ++j) {
					if (opt[i][j] > length) 
							    length = opt[i][j];
				}				
		}	
	return length;
	}
};


 int  makePalindrome(const vector<int> &v,const int sum)
 {
	 int n = v.size();
	 vector<int> rv = v;
     reverse(rv.begin(), rv.end());
        //这段程序其实就是原数组和逆序数组求公共子序列，得到最大子序列的和，
		//剩下要插入的数字之和就是原数组的和减去公共子序列的和
	   vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		  for (int i = 1; i <= n; ++i) {
		     for (int j = 1; j <= n; ++j) {
			    if (v[i - 1] == rv[j - 1]) 
				 dp[i][j] = dp[i - 1][j - 1] + v[i - 1];				
				
			    else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);				
						  
			 }
			
		  }		
	//        for(int i=0;i<n+1;++i){
	//            for(int j=0;j<n+1;++j){
	//                cout<<dp[i][j]<<" ";
	//            }
	//            cout<<endl;
	//        }
       //其中sum-dp[n][n]是需要插入的数字和
	
		  return sum + (sum - dp[n][n]);
 }


 int lengthOfLongestSubstring(string s) {
	 map<char, int> m;
	 int lastrepposition = -1, maxlen = 0;
	 for (size_t i = 0; i < s.size(); i++)
	 {
		 if (m.find(s[i]) != m.end()&&m[s[i]]>lastrepposition) 	 
			 lastrepposition == m[s[i]];
		 maxlen = maxlen > (i - lastrepposition) ? maxlen : lastrepposition;
	     
		 m[s[i]] = i;
	 }
	 return maxlen;
 }

 string longestPalindrome_dp_opt_way(string s) {
	 int n = s.size();
	 if (n <= 1) return s;
	 bool** matrix = (bool**)malloc(n * sizeof(bool*));
	 int start = 0,len = 0;
	 for (size_t i = 0; i < n; i++)
	 {
		 matrix[i] = (bool*)malloc((i + 1) * sizeof(bool));
		 memset(matrix[i], false, (i + 1) * sizeof(bool));
		 //matrix[i][i] = true;
		 for (size_t j = 0; j <i ; j++)
		 {
			 if (i = j || (s[i] = s[j] && (i - j <= 2 || matrix[i - 1][j + 1]))) {//i=j prevent the stituation in which i=j=0
				 matrix[i][j] = true;
				 if (len < (i - j + 1)) {
					 len = i - j + 1;
					 start = j;
				 }
			 }
		 }
	 }
	 for (int i = 0; i < n; i++) {
		 free(matrix[i]);
	 }
	 free(matrix);

	 return s.substr(start, len);
 }

 void findPalindrome(const string s,int left,int right ,int &start,int & len ){
	 while (s[left] == s[right] && left > 0 && right < s.size()-1)
	 {
		 left--;
		 right++;
	 }
	 if (len<right-left+1)
	 {
		 len = right - left + 1;
		 start = left ;
	 }
 }

 string longestPalindrome_recursive_way2(string s) {
	 int n = s.size();
	 if (n <= 1) return s;

	 int start = 0, len = 0;
	 for (size_t i = 0; i < n; i++)
	 {
		 findPalindrome(s, i, i, start, len);
		 findPalindrome(s, i, i+1, start, len);
	 }

	 return s.substr(start, len);
 }


 string intToRoman(int toBeConvert) noexcept(2>1) {
	 if (toBeConvert == 0) return "zero";

	 string symbol[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
	 int value[] = { 1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1 };
	 string result;

	 for (size_t i = 0; toBeConvert!=0; i++) 
	 {
		 while (toBeConvert - value[i] > 0)
		 {
			 toBeConvert -= value[i];
			 result += symbol[i];		 
		 }
	 }
	 return result;
 }
	 
int main()
{
	//string a = "11";
	//string b = "1";
	//vector<stringchar> str = { stringchar("abstract"),stringchar("abrupt"),stringchar("ability") };
	//string c = stringchar::longestCommonPrefix(str);

	//cout << c << endl;
	//cout << a << "+" << b << "=" <<stringchar::bitadd(a, b) << endl;
	string str1, str2;
	while (getline(cin, str1), getline(cin, str2)) {//continue to carry out if input another two str
		cout << stringchar::longestCommonSubstring(str1, str2)<<endl;
	}


	int n;
	while (cin >> n) {
		vector<int> v(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}
	cout <<	makePalindrome(v, sum)<<endl;
		
	return 0;
}


