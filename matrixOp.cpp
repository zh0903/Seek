/**********************************************************************************
*
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*
**********************************************************************************/
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &matrix) {

	int n = matrix.size();

	for (int i = 0; i < n/2; i++)
	{	
		int low = i, high = n - i - 1;
		int temp;
		for (int j = i; j < n-i-1; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[n-1-j][i];
			matrix[n - 1 - j][i] = matrix[n - i - 1][n - j - 1];
			matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];//[j]
			matrix[j][n - i - 1] = temp;

		}
	}
}

void printMatrix(vector<vector<int> > &matrix)
{
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%3d ", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
bool sortedMatrixSearch(const vector<vector<int>> &matrix,const int target) {
	if (matrix.size()<=0)
	{
		return false;
	}
	for (size_t i = 0; i < matrix.size(); i++)
	{
		if (target == matrix[i][matrix[i].size()])
			return true;
		else if (target> matrix[i][matrix[i].size()])
		{
			continue;
		}
		else
		{
			int low = 0,high=matrix[i].size()-1;
			int mid;
			while (low<=high)
			{
				mid = (low + high) / 2;
				if (matrix[i][mid] == target)
				{
					return true;
				}
				else if (matrix[i][mid] < target)
				{
					low = mid + 1;
				}
				else
					high = mid - 1;
			}
			return false;
			/*for (size_t j = 0; j < matrix[i].size(); j++)
			{
				if (target==matrix[i][j])
				{
					return true;
				}
				else if (target>)
				{

				}
			}*/
		}
	}
}

int main(int argc, char** argv)
{
	int n = 2;
	if (argc > 1) {
		n = atoi(argv[1]);
	}
	vector< vector<int> > matrix;
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		for (int j = 1; j <= n; j++) {
			v.push_back((i - 1)*n + j);
		}
		matrix.push_back(v);
	}

	printMatrix(matrix);
	rotate(matrix);
	printMatrix(matrix);

	return 0;
}