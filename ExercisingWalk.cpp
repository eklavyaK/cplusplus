#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if ((x2 == x1 && (a != 0 || b != 0)) || (y2 == y1 && (c != 0 || d != 0)) || (a - b > x - x1) || (b - a > x2 - x) || (c - d > y - y1) || (d - c > y2 - y))
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}