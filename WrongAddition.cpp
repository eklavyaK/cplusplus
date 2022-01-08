#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long int a = 0l, s = 0l;
        cin >> a >> s;
        int detect = 0;
        string b = "";
        while (s != 0 || a != 0)
        {
            if (s % 10 < a % 10)
            {
                if (s % 100 < a % 10 || s % 100 - a % 10 > 9)
                {
                    detect = 1;
                    break;
                }
                else
                {
                    b = to_string(s % 100 - a % 10) + b;
                    s = s / 100;
                    a = a / 10;
                }
            }
            else
            {
                b = to_string(s % 10 - a % 10) + b;
                s = s / 10;
                a = a / 10;
            }
        }
        if (detect == 1)
            cout << -1 << endl;
        else
            cout << stoll(b) << endl;
    }
    return 0;
}