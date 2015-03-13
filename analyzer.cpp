#include <iostream>

using namespace std;

/* Вычисление расиональной степени числа */

double power(double x, int n)
{
	double t = 1;
	for (int i = 0; i < n; ++i)
		t *= x;
	return t;
}

double root(double a, int n)
{
	double x, xx;
	xx = a/n;
	do {
		x = xx;
		xx = x - x / n + a / n / power(x,n-1);
	} while (x - xx > 1e-4 || xx - x > 1e-4);
	return xx;
}

int main()
{
	int n, m;
	double q;
	cin >> q >> n >> m;
 	/* q ^ (n/m) */
	if (m < 0) {
		n = -n;
		m = -m;
	}
	if (m % 2 == 0 && q < 0) {
		cout << "Not real" << endl;
		return 1;
	}
	if (m == 0 && n != 0) {
		if (q < 1 && q > -1) {
			cout << 0 << endl;
			return 0;
		} else {
			cout << "inf" << endl;
			return 0;
		}
	}
	cout << root(power(q, n), m) << endl;
}
