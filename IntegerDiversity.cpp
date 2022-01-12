#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n, k = 0;
		int count = 0, zerocount = 0;
		cin >> n;
		int a[101] = {0};
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			if (k < 0)
			{
				if (a[-k] < 2)
				{
					a[-k]++;
					count++;
				}
			}
			else if (k > 0)
			{
				if (a[k] < 2)
				{
					a[k]++;
					count++;
				}
			}
			else if (zerocount++ == 0)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}