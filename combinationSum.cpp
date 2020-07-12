#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void combinationSumHelper(const vector<int> &candidates, int start, int target, vector<int> &solution, vector< vector<int> > &result) {
	if (target < 0) {
		return;
	}
	if (target == 0) {
		result.push_back(solution);
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		//skip duplicates
		if ((i > start && candidates[i] == candidates[i - 1])||candidates[i]>target) {
			continue;
		}
		solution.push_back(candidates[i]);
		combinationSumHelper(candidates, i, target - candidates[i], solution, result);
		solution.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector< vector<int> > result;
	if (candidates.size() <= 0) {
		return result;
	}
	sort(candidates.begin(), candidates.end());

	vector<int> solution;
	combinationSumHelper(candidates, 0, target, solution, result);

	return result;
}

void combinationSumHelper2(const vector<int>& candidates, int start, int target, vector<vector<int>> &result, vector<int> sln) {
	if (target == 0)
	{
		result.push_back(sln);
	}
	if (target < 0)
	{
		return;
	}
	for (size_t i = start; i < candidates.size() - 1; i++)
	{
		if (i > start && candidates[i] == candidates[i - 1]) {
			continue;
		}
		sln.push_back(candidates[i]);
		combinationSumHelper2(candidates, i + 1, target - candidates[i], result, sln);
		sln.pop_back();
	}

}

vector<vector<int>> combinationSum2( vector<int>& candidates, int target) {
	vector<vector<int>> result;
	if (candidates.size() <= 0) {
		return result;
	}
	sort(candidates.begin(), candidates.end());
	vector<int> solution;
	combinationSumHelper2(candidates, 0, target, result, solution);

	return result;
}



void printMatrix(vector< vector<int> > &vv)
{
	for (int i = 0; i < vv.size(); i++) {
		cout << "[";
		for (int j = 0; j < vv[i].size(); j++) {
			cout << " " << vv[i][j];
		}
		cout << "]" << endl;;
	}
}

void printArray(vector<int> &v)
{
	cout << "{";
	for (int i = 0; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << "}" << endl;
}

class addtwoStr
{
public:
	string operator()(const string &num1, const string &num2) {
		if (num1.size()<=0||num2.size()<=0)
		{
			return"";
		}
		string result;
		for (size_t i = num1.size()-1; i >=0; i--){
			int carry=0;
			string val;
			for (size_t j = num2.size()-1; j >=0; j--){
				int v=(num2[j]-'0')*(num1[i]-'0')+carry;
				val.insert(val.begin(), v % 10 + '0');
				carry = v / 10;
			}
			if (carry>0)
			{
				val.insert(val.begin(), carry+'0');
			}
			for (size_t k = i; k < num1.size(); k++)
			{
				val.push_back('0');
			}
			result = addStr(result, val);			
		}
	}
	string addStr(string result,string val) {
		
		if (result.size() == 0) return val;
		if (val.size() == 0) return result;
		
		string res;
		int carry = 0;
		if (result.size()<val.size())
		{
			swap(result, val);
		}
		for (size_t i = 0; i < result.size(); i++)
		{
			if (i<val.size())
			{
				res[i] = ((result[i] - '0') + (val[i] - '0') + carry)/10 + '0';
				carry = ((result[i] - '0') + (val[i] - '0')) % 10;
			}
			else
			{
				res[i] = ((result[i]-'0') + carry)+'0';
				carry = 0;
			}
		
			
		}
		if (carry > 0) {
			res.insert(res.begin(), carry + '0');
		}
		return res;
	}



};


int main(int argc, char** argv)
{
	int a[] = { 1,2,3,7 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	int target = 6;
	cout << "array  = ";
	printArray(v);
	cout << "target = " << target << endl;

	vector< vector<int> > vv = combinationSum2(v, target);
	printMatrix(vv);

	return 0;
}