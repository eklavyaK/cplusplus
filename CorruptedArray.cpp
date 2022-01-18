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
        int n, index1, index2, max1 = 0, max2 = 0, detect = 0;
        cin >> n;
        int a[n + 2];
        long long int sum = 0l;
        for (int i = 0; i < n + 2; i++)
        {
            cin >> a[i];
            if (max1 < a[i])
            {
                max1 = a[i];
                index1 = i;
            }
            sum = sum + a[i];
        }
        sum = sum - 2 * max1;
        for (int i = 0; i < n + 2; i++)
            if (sum == a[i] && i != index1)
            {
                detect = -1;
                index2 = i;
                break;
            }
        if (detect != -1)
        {
            for (int i = 0; i < n + 2; i++)
            {
                if (max2 < a[i] && i != index1)
                {
                    max2 = a[i];
                    index2 = i;
                }
            }
            sum = sum + max1 - a[index2];
            if (sum == a[index2])
                detect = -1;
            if (detect == -1)
                {
                    for (int i = 0; i < n + 2; i++)
                    if (i != index2 && i != index1)
                        cout << a[i] << " ";
                }
            else
                cout << -1;
        }
        else
            for (int i = 0; i < n + 2; i++)
                if (i != index2 && i != index1)
                    cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}