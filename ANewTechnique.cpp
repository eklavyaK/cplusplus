#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        int k;
        cin >> k;
        int x, y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (a[i][j] == k)
                {
                    x = i;
                    y = j;
                    k = 0;
                    break;
                }
            if (k == 0)
                break;
        }
        for (int i = 0; i < m; i++)
            cout << a[x][i] << " ";
        cout << '\n';
        for (int i = 1; i < n; i++)
        {
            cin >> k;
            for (int j = 0; j < n; j++)
                if (a[j][y] == k)
                {
                    for (int r = 0; r < m; r++)
                        cout << a[j][r] << " ";
                    cout << endl;
                    break;
                }
        }
        int d = n * (m - 1), p;
        while (d-- > 0)
            cin >> p;
        //while(m-->0) cin.ignore(256,'\n');
    }
}