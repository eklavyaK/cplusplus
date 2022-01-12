#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string dummy;
    getline(cin, dummy);
    while (t-- > 0)
    {
        string s;
        getline(cin, s);
        int a_count = 0, b_count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                a_count++;
            else
            {
                if (a_count > 0)
                    a_count--;
                else
                    b_count++;
            }
        }
        if (b_count % 2 == 0)
            b_count = 0;
        else
            b_count = 1;
        cout << (a_count + b_count) << endl;
    }
}