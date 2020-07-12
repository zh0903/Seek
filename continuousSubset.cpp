#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<vector<int>> contSubset(const vector<int> raw)
{
	vector<vector<int>> result;
	vector<int> set;
	for (size_t i = 0; i < raw.size(); i++)
	{
		for (size_t j = 0; j < raw.size()-i; j++)
		{
			set.assign(raw.begin()+j,raw.begin()+i+j+1); //复制不包括末尾迭代器
			result.push_back(set);
		}
	}
	return result;
}

void printResult(const vector<vector<int> >& result)
{
	for (int i = 0; i<result.size(); i++) {
		cout << "{";
		for (int j = 0; j<result[i].size(); j++) {
			cout << " " << result[i][j];
		}
		cout << " }" << endl;
	}
}

int main()
{
	clock_t start_time, end_time;
	vector<int> raw= { 1,0,0,8,6 };
	start_time = clock();
	vector<vector<int>> result = contSubset(raw);
	end_time = clock();
	printResult(result);
	double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("%f seconds\n", Times);
	system("pause");
}
