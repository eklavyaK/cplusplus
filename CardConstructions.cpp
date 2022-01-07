#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n, result = 0;
		cin >> n;
		while (n > 1)
		{
			long double x = ((long double)pow(49 + (long long int)12 * (2 * n - 4), 0.5) - 7)/6;
			int temp = x;
			if((1.5 * temp + 2) * (temp + 1)<n && (1.5 * temp + 3.5) * (temp + 2)>n)
				n = n - (1.5 * temp + 2) * (temp + 1);
			else if((1.5 * temp + 2) * (temp + 1)>n && (1.5 * temp + 0.5) * temp<n)
				n = n - (1.5 * temp + 0.5) * temp;
			else {result++;break;}
			result++;
		}
		cout << result << endl;
	}
	return 0;
}