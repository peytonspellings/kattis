#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXS = 100;
const int MAXM = 9;

int xs[5000], ys[5000];

bool repeat(int n)
{
	for(int i=0; i<n; i++) {
		if (xs[i] == xs[n] && ys[i] == ys[n])
			return true;
	}
	return false;
}

int main()
{
	int n, m, s, t;
	int x, y;

	cin >> n >> m >> s >> t;
		if (n < 1 || n > MAXS) {
			cout << "ERROR: invalid n " << n << endl; return 1; }
		if (m < 1 || m > (n*(n-1))/2) {
			cout << "ERROR: invalid m " << m << endl; return 2; }
		if (s < 0 || s > n) {
			cout << "ERROR: invalid s " << s << endl; return 3; }
		if (t < 1 || t > MAXM) {
			cout << "ERROR: invalid t " << t << endl; return 4; }
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			if (x < 0 || x > n) {
				cout << "ERROR: invalid x " << x << " in line " << i << endl; return 5; }
			if (y < 0 || y > n) {
				cout << "ERROR: invalid y " << y << " in line " << i << endl; return 6; }
			xs[i] = x, ys[i] = y;
			if (repeat(i)) {
				cout << "ERROR: repeat connection " << x << ',' << y << " in line " << i << endl; return 7; }
		}
return 42;
}
