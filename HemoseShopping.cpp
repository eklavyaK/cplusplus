#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x;
        cin >> n >> x;
        int a[n], clone[n], detect = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            clone[i] = a[i];
        }
        sort(clone, clone + n);
        for (int i = n - x; i < x; i++)
        {
            if (clone[i] != a[i])
            {
                detect = 1;
                break;
            }
        }
        if (detect == 1)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}