#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, pull;
        cin >> n;
        long long int sum = 0l, k = 0l;
        vector<int> v;
        map<int, long long int> map;
        for (int i = 0; i < n; i++)
        {
            cin >> pull;
            if (map[pull]++ == 0)
            {
                v.push_back(pull);
            }
            sum = sum + pull;
        }
        int l = 0, r = v.size() - 1;
        long double mean = (long double)sum * 2 / n;
        if (mean == int(mean))
        {
            sort(v.begin(), v.end());
            while (l < r)
            {
                if (v[l] + v[r] == mean)
                {
                    k = k + map[v[l]] * map[v[r]];
                    l++;
                    r--;
                }
                else if (v[l] + v[r] > mean)
                    r--;
                else
                    l++;
            }
            if (l == r && v[l] * 2 == mean)
                k = k + map[v[l]] * (map[v[l]] - 1) / 2;
        }
        else
            k = 0;
        cout << k << endl;
    }
}