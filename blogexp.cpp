// blogexp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Attempting to put the Queen into[row, col], check it is valid or not
bool isvalid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn) {
	for (int i = 0; i < attemptedRow; i++)
	{
		if (attemptedColumn == queenInColumn[i] || abs(i - attemptedRow) == abs(attemptedColumn - queenInColumn[i]))
			return false;
	}
	return true;
}
void solveNQueensRecursive(int n, int row, vector<int>& solution, vector< vector<string>> &result)
{
	if (row == n) {    // equal to N
		vector<string> solutionboard(n, string(n, '.'));
		for (int row = 0; row < n; row++) {
			solutionboard[row][solution[row]] = 'Q';
		}
		result.push_back(solutionboard);
		return;
	}
	for (size_t col = 0; col < n; col++)
	{
		if (isvalid(col, row, solution))
		{
			solution[row] = col;
			solveNQueensRecursive(n, row + 1, solution, result);
		}
	}
}


vector< vector<string> > solveNQueens(int n) {
	vector< vector<string> > result;
	vector<int> solution(n);

	solveNQueensRecursive(n, 0, solution, result);

	return result;
}



void printMatrix(vector< vector<string> >& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		cout << "-----------" << endl;
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << endl;
		}
	}
}

int main()

{
	vector< vector<string> > result;
	result = solveNQueens(8);
	printMatrix(result);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
