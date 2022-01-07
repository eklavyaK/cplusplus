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
		int one_count = 0, zero_count = 0, k;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			if (k == 1)
				one_count++;
			else
				zero_count++;
		}
		if (one_count > zero_count)
		{
			if (zero_count % 2 == 0)
			{
				cout << one_count << endl;
				while (one_count-- > 0)
					cout << 1 << " ";
				cout << endl;
			}
			else
			{
				cout << --one_count << endl;
				while (one_count-- > 0)
					cout << 1 << " ";
				cout << endl;
			}
		}
		else
		{
			cout << zero_count << endl;
			while (zero_count-- > 0)
				cout << 0 << " ";
			cout << endl;
		}
	}
}