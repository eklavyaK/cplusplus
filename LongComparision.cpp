#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	cin >> t;
	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		double y = log10(1.0 * a / c) + b - d;
		if (y == 0)
			printf("=");
		else
			printf(y > 0 ? ">" : "<");
		printf("\n");
	}
	return 0;
}