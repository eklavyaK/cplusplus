#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		if (x >= y)
		{
			if (b - n <= x)
			{
				if (b - n >= y)
					cout << (long long int)(b - n) * a << endl;
				else
				{
					int temp = n - (b - y);
					if (a - temp >= x)
						cout << (long long int)(a - temp) * y << endl;
					else
						cout << (long long int)x * y << endl;
				}
			}
			else if (a - n <= x)
				cout << (long long int)x * (b - n + (a - x)) << endl;
			else if (a > b)
				cout << (long long int)a * (b - n) << endl;
			else
				cout << (long long int)b * (a - n) << endl;
		}
		else if (y > x)
		{
			if (a - n <= y)
			{
				if (a - n >= x)
					cout << (long long int)(a - n) * b << endl;
				else
				{
					int temp = n - (a - x);
					if (b - temp >= y)
						cout << (long long int)(b - temp) * x << endl;
					else
						cout << (long long int)x * y << endl;
				}
			}
			else if (b - n <= y)
				cout << (long long int)y * (a - n + (b - y)) << endl;
			else if (a > b)
				cout << (long long int)a * (b - n) << endl;
			else
				cout << (long long int)b * (a - n) << endl;
		}
	}
}