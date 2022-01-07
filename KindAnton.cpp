#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int count1 = n, count_neg1 = n, detect = 0;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1 && count1==n)
            {
                count1 = i;
                if (detect == 0)
                    detect = 1;
                else break;
            }
            else if (a[i] == -1 && count_neg1==n)
            {
                count_neg1 = i;
                if (detect == 0)
                    detect = 1;
                else break;
            }
        }
        detect = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] < b[i])
            {
                if (count1 >= i)
                {
                    detect = 1;
                    break;
                }
            }
            else if (a[i] > b[i])
            {
                if (count_neg1 >= i)
                {
                    detect = 1;
                    break;
                }
            }
        }
        if (detect == 1)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}