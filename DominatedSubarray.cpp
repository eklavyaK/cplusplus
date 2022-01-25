#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        int n, k;
        cin >> n;
        int detect = 0;
        map<int, pair<int, int>> map;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (map[k].first != 0)
            {
                map[k].second = map[k].second == 0 ? i - map[k].first + 2 : min(i - map[k].first + 2, map[k].second);
                map[k].first = i + 1;
            }
            else
                map[k].first = i + 1;
        }
        int m = INT_MAX;
        for (auto i : map)
            if (i.second.second != 0)
                {m = min(m, i.second.second); detect = 1;}
        if (detect)
            cout << m << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}