#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int f0 = s.find('0');
        int f1 = s.find('1');
        if (f0 >= 0 && f1 >= 0)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == s[i + 1])
                {
                    if (s[i] == '0')
                        cout << s[i] << '1';
                    else
                        cout << s[i] << '0';
                }
                else
                    cout << s[i];
            }
        }
        else
            cout << s;
        cout << endl;
    }
}