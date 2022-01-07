#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p;
    cin >> p;
    while (p-- > 0)
    {
        int n;
        cin >> n;
        int t;
        cin >> t;
        int k;
        int track = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (2 * k < t)
                cout << 0 << " ";
            else if (t == 2 * k)
            {
                if ((track++) % 2 == 0)
                    cout << 1 << " ";
                else
                    cout << 0 << " ";
            }
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
}