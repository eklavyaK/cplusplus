#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        int a[n][2];
        int sum = k;
        for (int i = 0; i < n; i++)
            cin >> a[i][0];
        for (int i = 0; i < n; i++)
            cin >> a[i][1];
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1-i; j++)
                if (a[j][0] > a[j + 1][0])
                {
                    int temp = a[j][0];
                    a[j][0] = a[j + 1][0];
                    a[j + 1][0] = temp;
                    temp = a[j][1];
                    a[j][1] = a[j + 1][1];
                    a[j + 1][1] = temp;
                }
        for (int i = 0; i < n; i++)
        {
            if (sum >= a[i][0])
                sum += a[i][1];
            else
                break;
        }
        cout << sum << endl;
    }
    return 0;
}