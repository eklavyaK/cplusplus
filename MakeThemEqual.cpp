#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, detect;
        char c;
        string s;
        cin >> n >> c >> s;
        string temp(n, c);
        if (s.compare(temp) == 0)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == c)
            {
                detect = i + 1;
                break;
            }
        if (detect * 2 > n)
            cout << 1 << '\n'
                 << detect << endl;
        else
            cout << 2 << '\n'
                 << n - 1 << " " << n << endl;
    }
}