#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n;
        int a[200001] = {0}, count = 0, max = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (a[k] == 0)
                count++;
            a[k]++;
            if (a[k] > max)
                max = a[k];
        }
        if (max > count)
            cout << count << endl;
        else if (max == count)
            cout << count - 1 << endl;
        else
            cout << max << endl;
    }
}