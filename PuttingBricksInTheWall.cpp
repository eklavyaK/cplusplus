#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	string dummy;
	string r1, r2, r3;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		cin >> r1;
		cin >> r2;
		cin >> r3;
		if (r1.at(1) == r1.at(2))
		{
			if (r1.at(1) == '0')
			{
				if (r2[0] == '1' && r2[1] == '1' && r3[0] == '1')
				{
					cout << 2 << endl;
					cout << 1 << " " << 3 << endl;
					cout << 2 << " " << 1 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '1' && r3[0] == '0')
				{
					cout << 2 << endl;
					cout << 1 << " " << 3 << endl;
					cout << 3 << " " << 1 << endl;
				}
				else if (r2[0] == '1' && r2[1] == '0' && r3[0] == '1')
				{
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
					cout << 3 << " " << 1 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '1' && r3[0] == '1')
				{
					cout << 1 << endl;
					cout << 1 << " " << 3 << endl;
				}
				else if (r2[0] == '1' && r2[1] == '1' && r3[0] == '0')
				{
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
					cout << 2 << " " << 2 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '0' && r3[0] == '0')
				{
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
					cout << 2 << " " << 1 << endl;
				}
				else if (r2[0] == '1' && r2[1] == '0' && r3[0] == '0')
				{
					cout << 1 << endl;
					cout << 1 << " " << 2 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '0' && r3[0] == '1')
				{
					cout << 2 << endl;
					cout << 1 << " " << 3 << endl;
					cout << 2 << " " << 2 << endl;
				}
			}
			else
			{
				if (r2[0] == '1' && r2[1] == '1' && r3[0] == '1')
				{
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
					cout << 2 << " " << 1 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '1' && r3[0] == '0')
				{
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
					cout << 3 << " " << 1 << endl;
				}
				else if (r2[0] == '1' && r2[1] == '0' && r3[0] == '1')
				{
					cout << 2 << endl;
					cout << 1 << " " << 3 << endl;
					cout << 3 << " " << 1 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '1' && r3[0] == '1')
				{
					cout << 1 << endl;
					cout << 1 << " " << 2 << endl;
				}
				else if (r2[0] == '1' && r2[1] == '1' && r3[0] == '0')
				{
					cout << 2 << endl;
					cout << 1 << " " << 3 << endl;
					cout << 2 << " " << 2 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '0' && r3[0] == '0')
				{
					cout << 2 << endl;
					cout << 1 << " " << 3 << endl;
					cout << 2 << " " << 1 << endl;
				}
				else if (r2[0] == '1' && r2[1] == '0' && r3[0] == '0')
				{
					cout << 1 << endl;
					cout << 1 << " " << 3 << endl;
				}
				else if (r2[0] == '0' && r2[1] == '0' && r3[0] == '1')
				{
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
					cout << 2 << " " << 2 << endl;
				}
			}
		}
		else
		{
			if (r1[1] == r2[1])
			{
				if (r1[1] == r2[0] && r1[1] == r3[0])
				{
					cout << 2 << endl;
					cout << 2 << " " << 2 << endl;
					cout << 3 << " " << 1 << endl;
				}
				else if (r1[1] != r2[0] && r1[1] == r3[0])
				{
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
					cout << 1 << " " << 3 << endl;
				}
				else if (r1[1] == r2[0] && r1[1] != r3[0])
				{
					cout << 1 << endl;
					cout << 2 << " " << 2 << endl;
				}
				else if (r1[1] != r2[0] && r1[1] != r3[0])
				{
					cout << 2 << endl;
					cout << 2 << " " << 1 << endl;
					cout << 2 << " " << 2 << endl;
				}
			}
			else
			{
				if (r1[1] != r2[0] && r1[1] == r3[0])
				{
					cout << 2 << endl;
					cout << 2 << " " << 1 << endl;
					cout << 3 << " " << 1 << endl;
				}
				else if (r1[1] == r2[0] && r1[1] == r3[0])
				{
					cout << 1 << endl;
					cout << 3 << " " << 1 << endl;
				}
				else if (r1[1] != r2[0] && r1[1] != r3[0])
				{
					cout << 1 << endl;
					cout << 2 << " " << 1 << endl;
				}
				else
					cout << 0 << endl;
			}
		}
		n = n - 3;
		while (n-- > 0)
			cin >> dummy;
	}
}