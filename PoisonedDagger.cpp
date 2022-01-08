#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        long long int h = 0l, k, sum = 0l;
        cin >> n >> h;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1)
        {
            cout << h << endl;
            continue;
        }
        for (int i = 1; i < n; i++)
            b[i - 1] = a[i] - a[i - 1];
        sort(b, b + n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            k = b[i];
            if ((n - i) * k + sum > h)
            {
                k = ceil((long double)(h - sum) / (n - i));
                break;
            }
            else
            {
                sum = sum + b[i];
                if (i == n - 2)
                    k = h - sum;
            }
        }
        cout << k << endl;
    }
}