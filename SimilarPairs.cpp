#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n, count = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] % 2 == 0)
				count++;
		}
		bool result = true;
		if (count % 2 == 1)
		{
			sort(a, a + sizeof(a) / sizeof(a[0]));
			result = false;
			for (int i = 0; i < n - 1; i++)
			{
				if (a[i + 1] - a[i] == 1 && ((a[i] % 2 == 1 && a[i + 1] % 2 == 0) || (a[i] % 2 == 0 && a[i + 1] % 2 == 1)))
					result = true;
			}
		}
		if (result)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}