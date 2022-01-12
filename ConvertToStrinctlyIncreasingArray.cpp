#include <iostream>
using namespace std;
int main()
{
	int n, a;
	cin >> n;
	cout << n + 1 << endl;
	cout << 1 << " " << n << " " << 200001 << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cout << 2 << " " << i + 1 << " " << (200001 + a - i) << endl;
	}
	return 0;
}