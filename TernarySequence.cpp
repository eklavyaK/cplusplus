#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int x1, y1, z1, x2, y2, z2, sum = 0;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		if (z1 <= y2)
		{
			sum = sum + 2 * z1;
			if (z2 > x1)
				sum = sum - 2 * (z2 - x1);
		}
		else
		{
			sum = sum + 2 * y2;
			if (z2 > x1)
				if (z2 - x1 > z1 - y2)
					sum = sum - 2 * (z2 - x1 - z1 + y2);
		}
		cout << sum << endl;
	}
}