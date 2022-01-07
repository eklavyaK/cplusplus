#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int k, n, m, r = 0, c = 0;
		cin >> n >> m;
		int row[n] = {0}, col[m] = {0};
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> k;
				if (k == 1)
				{
					if (row[i] == 0)
					{
						row[i] = 1;
						r++;
					}
					if (col[j] == 0)
					{
						col[j] = 1;
						c++;
					}
				}
			}
		int result = min(n - r, m - c);
		if (result % 2 == 0)
			cout << "Vivek" << endl;
		else
			cout << "Ashish" << endl;
	}
	return 0;
}