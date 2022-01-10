#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, a, b, c;
        cin >> n >> m;
        bool arr[n] = {false};
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            arr[b] = true;
        }
        for (int j = 0; j < n; j++)
        {
            if (arr[j])
                ;
            else
            {
                for (int i = 1; i <= n; i++)
                    if (i != j + 1)
                        cout << j + 1 << " " << i << '\n';
                break;
            }
        }
    }
}