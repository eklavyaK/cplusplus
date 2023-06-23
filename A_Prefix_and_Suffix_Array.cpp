#include <bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

void code()
{
    int n;
    cin >> n;
    vector<string> st;
    vector<char> ch;
    for (int i = 0; i < 2 * n - 2; i++)
    {
        string s;
        cin >> s;
        if (s.size() == n - 1)
            st.push_back(s);
        if (s.size() == 1)
            ch.push_back(s[0]);
    }
    if (ch[0] == ch[1])
    {
        reverse(st[0].begin(), st[0].end());
        if (st[0] == st[1])
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        code();
    return 0;
}