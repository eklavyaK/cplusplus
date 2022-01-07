#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, odd_count = 0, end = 1, begin = 0, track = 1;
        cin >> n;
        int a[2 * n][2];
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> k;
            if (k % 2 == 1)
            {
                odd_count++;
                a[begin][0] = k;
                a[begin++][1] = track++;
            }
            else
            {
                a[2 * n - end][0] = k;
                a[2 * n - end++][1] = track++;
            }
        }
        if (odd_count % 2 == 0)
            for (int i = 2; i < 2 * n; i += 2)
                cout << a[i][1] << " " << a[i + 1][1] << endl;
        else
            for (int i = 1; i < 2 * n - 1; i += 2)
                cout << a[i][1] << " " << a[i + 1][1] << endl;
    }
    return 0;
}