#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (n < 3)
		{
			cout << 0 << endl;
			continue;
		}
		int min = n;
		for (int j = 0; j < n - 1; j++)
			for (int i = j + 1; i < n; i++)
			{
				int count = 0;
				for (int r = 0; r < n; r++)
					if ((a[j] - a[i]) * (r - i) != (a[r] - a[i]) * (j - i))
						count++;
				if (count < min)
					min = count;
			}
		cout << min << endl;
	}
	return 0;
}