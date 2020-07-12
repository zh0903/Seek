#include<iostream>
#include<Cmath>
//explore ::
using namespace std;
class CPoint
{
private:
	double x;
	double y;
public:
	CPoint(double xx = 0, double yy = 0) :x(xx), y(yy) {}
	friend void distance(CPoint &, CPoint &);
};
void distance(CPoint &p1, CPoint &p2)
{
	double l;
	l = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	cout << l;
}

class Solution {
public:
	bool isPalindrome(string s) {
		s = removeNoise(s);
		for (int i = 0; i<s.size() / 2; i++) {
			if (s[i] != s[s.size() - i - 1]) {
				return false;
			}
		}
		return true;
	}

	string removeNoise(string& s) {
		string d;
		for (int i = 0; i<s.size(); i++) {
			if (::isalpha(s[i]) || ::isdigit(s[i])) {
				d.push_back(::tolower(s[i]));
			}
		}
		return d;
	}
};

int main()
{
	CPoint t1(1, 2), t2(2, 3);
	::distance(t1, t2);
	cout << endl << ::isalpha('b');
	system("pause");
	
	return 0;
}


