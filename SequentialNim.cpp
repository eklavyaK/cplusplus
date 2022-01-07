#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, i;
        cin >> n;
        int detect = 0;
        for (i = 1; i <= n; i++)
        {
            cin >> k;
            if (detect == 0 && k != 1)
            {
                if (i % 2 == 1)
                    cout << "First" << endl;
                else
                    cout << "Second" << endl;
                detect = 1;
            }
        }
        if (detect == 0)
        {
            if (n % 2 == 1)
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
        //cin.ignore(256,'\n');
    }
}