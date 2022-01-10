#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, detecta = 0, detectb = 0;
        string s;
        cin >> n >> s;
        char a = '0', b = '0';
        int l = 0, r = n - 1, count = 0;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                r--;
                l++;
            }
            else
            {
                a = s[l];
                b = s[r];
                break;
            }
        }
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        int count_a = 0, count_b = 0;
        int stl = l, str = r;
        count_a++;
        l++;
        count_b++;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else if (s[l] == a)
            {
                count_a++;
                l++;
            }
            else if (s[r] == a)
            {
                count_a++;
                r--;
            }
            else
            {
                detecta = 1;
                break;
            }
        }
        str--;
        while (stl < str)
        {
            if (s[stl] == s[str])
            {
                stl++;
                str--;
            }
            else if (s[stl] == b)
            {
                count_b++;
                stl++;
            }
            else if (s[str] == b)
            {
                count_b++;
                str--;
            }
            else
            {
                detectb = 1;
                break;
            }
        }
        if (count_a <= count_b)
        {
            if (detecta == 1)
            {
                if (detectb == 1)
                    cout << -1 << endl;
                else
                    cout << count_b << endl;
            }
            else
                cout << count_a << endl;
        }
        else
        {
            if (detectb == 1)
            {
                if (detecta == 1)
                    cout << -1 << endl;
                else
                    cout << count_a << endl;
            }
            else
                cout << count_b << endl;
        }
    }
}