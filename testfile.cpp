#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, count1 = 0, countneg1 = 0, detect = 0;
        cin >> n;
        int count_1[n] = {0}, count_neg1[n] = {0}, a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
            {
                count_1[i] = count1++;
                count_neg1[i] = countneg1;
            }
            else if (a[i] == -1)
            {
                count_1[i] = count1;
                count_neg1[i] = countneg1++;
            }
            else
            {
                count_1[i] = count1;
                count_neg1[i] = countneg1;
            }
        }
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] < b[i])
            {
                if (count_1[i] == 0)
                {
                    detect = 1;
                    break;
                }
            }
            else if (a[i] > b[i])
            {
                if (count_neg1[i] == 0)
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