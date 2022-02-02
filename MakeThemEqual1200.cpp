#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n], d = 0;
    map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        map[a[i]]++;
    }
    bool detect = true;
    double k = (double)(*max_element(a, a + n) + *min_element(a, a + n)) / 2;
    if (map.size() < 3)
    {
        k != int(k) ? cout << (*max_element(a, a + n) - *min_element(a, a + n)) << endl : cout << k - *min_element(a, a + n) << endl;
        exit(0);
    }
    if (k != int(k))
    {
        cout << -1 << endl;
        exit(0);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (detect)
            {
                if (a[i] != k)
                {
                    d = abs(a[i] - k);
                    detect = false;
                }
            }
            else if (a[i] != k && d != abs(a[i] - k))
            {
                detect = true;
                break;
            }
        }
    }
    if (detect)
        cout << -1 << endl;
    else
        cout << d << endl;
    return 0;
}