﻿#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> letterCombinations(string digits) {
	char  phone[10][4] = { {' ',  '\0', '\0', '\0' }, //0
						 {'\0', '\0', '\0', '\0' }, //1
						 {'a',  'b',  'c',  '\0' }, //2
						 {'d',  'e',  'f',  '\0' }, //3
						 {'g',  'h',  'i',  '\0' }, //4
						 {'j',  'k',  'l',  '\0' }, //5
						 {'m',  'n',  'o',  '\0' }, //6
						 {'p',  'q',  'r',  's'  }, //7
						 {'t',  'u',  'v',  '\0' }, //8
						 {'w',  'x',  'y',  'z'  }  //9
	};

	vector<string> result;
	vector<string> r;    //工具人

	if (digits.size() <= 0) {//没数字返回
		result.push_back("");
		return result;
	}

	for (int i = 0; i < digits.size(); i++) {

		if (!isdigit(digits[i])) {		//不是数字返回
			return r;                  
		}

		int d = digits[i] - '0';

		if (result.size() == 0) {
			for (int j = 0; j < 4 && phone[d][j] != '\0'; j++) {
				string s;
				s += phone[d][j];
				result.push_back(s);
			}
			continue;
		}

		for (int j = 0; j < result.size(); j++) {
			for (int k = 0; k < 4 && phone[d][k] != '\0'; k++) {
				string s = result[j] + phone[d][k];
				//sort(s.begin(), s.end());
				r.push_back(s);
			}
		}
		result = r;
	}
	//sort(result.begin(), result.end());

	return result;
}

void printVector(vector<string>& ss) {
	cout << "{ ";
	for (int i = 0; i < ss.size(); i++) {
		if (i > 0) cout << ", ";
		cout << ss[i];
	}
	cout << " }" << endl;
}

int main(int argc, char**argv)
{
	string s = "23";
	if (argc > 1) {
		s = argv[1];
	}
	vector<string> ss = letterCombinations(s);
	printVector(ss);
	return 0;
}