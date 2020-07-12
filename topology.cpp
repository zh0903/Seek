// topology.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

string word_order(vector<string>& words) {

	if (words.size() == 0)    return "invalid";

	char first = words[0][0];
	set<char> character;

	unordered_map<char, int> indegree;
	unordered_map<char, multiset<char>> hash;

	unordered_map<char, char>  nextt;

	for (auto word : words) {
		for (auto ch : word)
			indegree[ch] = 0;
	}

	for (int i = 1; i < words.size(); i++)
	{
		int k = 0, 
			len1 = words[i - 1].size(), 
			len2 = words[i].size();
		for (size_t l = 0; l < len2; l++)
		{
			character.insert(words[i][l]);
		}

		while (k < min(len1, len2))
		{
			if (words[i - 1][k] != words[i][k])
			{
				if (nextt.count(words[i-1][k])==0)
				{
					nextt[words[i - 1][k]] == words[i][k];
				}
				break;
			}
		}
	}
	string str;
	
	return str;

}

int main() {
	vector<string> words;
	string str;
	while (cin >> str) {
		words.push_back(str);
		char ch = getchar();
		if (ch == '\n') break;
	}
	string res = word_order(words);
	cout << res << endl;
	return 0;

}
