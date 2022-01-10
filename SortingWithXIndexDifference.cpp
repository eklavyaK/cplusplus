#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x, max, track = 0, detect = 0;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (x == 1)
        {
            cout << "yes" << endl;
            continue;
        }
        vector<int> v1, v2;
        int len = n / x;
        for (int j = 0; j < x - 1 && detect == 0;)
        {
            for (int i = j++; i < n; i += x)
                v1.push_back(a[i]);
            sort(v1.begin(), v1.end());
            for (int i = j; i < n; i += x)
                v2.push_back(a[i]);
            sort(v2.begin(), v2.end());
            for (int i = 0; i < len; i++)
                if (v1[i] > v2[i])
                {
                    detect = 1;
                    break;
                }
            if (v1.size() != v2.size())
                if (v1[len] < v2[len - 1])
                {
                    detect = 1;
                    break;
                }
        }
        if (detect == 1)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}