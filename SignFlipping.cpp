#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (k > 0)
            {
                if (i % 2 == 0)
                    cout << k << " ";
                else
                    cout << -k << " ";
            }
            else
            {
                if (i % 2 == 0)
                    cout << -k << " ";
                else
                    cout << k << " ";
            }
        }
        cout << endl;
    }
}