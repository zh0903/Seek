#include<string>
#include<sstream>
#include<vector>
using namespace std;

vector<int> split(const string s, char delim, vector<int> &elem)
{
	stringstream inputs(s);
	string item;
	while (getline(inputs, item, delim))
	{
		elem.push_back(atoi(item.c_str()));
	}
	return elem;
}
vector<int> split(const string s, char delim)
{
	vector<int> elems;
	split(s, delim, elems);
	return elems;
}


void rightTrimZero(vector<int> &v) {
	while (v.back() == 0) {
		v.pop_back();
	}
}

int compareVersion(string version1, string version2) {

	//split the version by delimer '.'
	vector<int> ver1 = split(version1, '.');
	vector<int> ver2 = split(version2, '.');

	//remove the right Zeros
	rightTrimZero(ver1);
	rightTrimZero(ver2);

	//compare two versions 
	for (int i = 0; i<ver1.size() && i < ver2.size(); i++) {
		if (ver1[i] < ver2[i]) {
			return -1;
		}
		else if (ver1[i] > ver2[i]) {
			return 1;
		}
	}           //if the above for-loop is not returned, which means they are equal so far
				//then check the length.
	//e.g.  1.0 1.0.1
	if (ver1.size() > ver2.size()) {
		return 1;
	}
	else if (ver1.size() < ver2.size()) {
		return -1;
	}

	return 0;

}