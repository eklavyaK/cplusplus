#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a1, b1;
        cin >> a1 >> b1;
        int a = max(a1, b1), b = min(a1, b1);
        if (a / 2 >= b)
        {
            cout << b << endl;
            continue;
        }
        int result = 0;
        result = a - b;
        b = b - result;
        if (b % 3 == 2)
            cout << ((b / 3) * 2 + result + 1) << endl;
        else
            cout << ((b / 3) * 2 + result) << endl;
    }
    return 0;
}