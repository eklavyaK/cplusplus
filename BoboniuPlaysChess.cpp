#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << x << " " << y << endl;
        for (int j = 1; j <= m; j++)
        {
            if (j != y)
                cout << x << " " << j << endl;
        }
        if (temp % 2 == 0)
        {
            y = m;
            temp++;
        }
        else
        {
            y = m - 1;
            temp++;
        }
        if (x == n)
            x = 1;
        else
            x++;
    }
}