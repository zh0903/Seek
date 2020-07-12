﻿// operaterr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
		cout << item<<endl;
	}
	return elems;
}


vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}


string simplifyPath(string path) {

	string result;
	vector<string> elems = split(path, '/');

	int ignor = 0;
	for (int i = elems.size() - 1; i >= 0; i--) {

		if (elems[i] == "" || elems[i] == ".") {
			continue;
		}
		if (elems[i] == "..") {
			ignor++;
			continue;
		}
		if (ignor > 0) {
			ignor--;
			continue;
		}
		if (result.size() == 0) {
			result = "/" + elems[i];
		}
		else {
			result = "/" + elems[i] + result;
		}
	}

	return  result.size() ? result : "/";

}

int main(int argc, char** argv)
{
	string path("/a/./b/../../c/");
	if (argc > 1) {
		path = argv[1];
	}

	cout << path << " : " << simplifyPath(path) << endl;
}