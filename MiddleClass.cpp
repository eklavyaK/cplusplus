#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x, count = 0;
        cin >> n >> x;
        int a[n];
        long long int sum = 0l;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] >= x)
            {
                count++;
                sum = sum + a[i];
            }
        }
        sort(a, a + n);
        for (int i = n - count - 1; i >= 0; i--)
        {
            if ((sum + a[i]) / (count + 1) >= x)
            {
                sum = sum + a[i];
                count++;
            }
        }
        cout << count << endl;
    }
}