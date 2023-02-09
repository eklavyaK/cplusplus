#include <bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int mod = 998244353;

int exp(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

void code()
{
    int n, m;
    cin >> n >> m;
    int arr[n + 1]{}, gd = 1;
    for (int i = 1; i <= n; i++)
    {
        bool f = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                f = false;
                break;
            }
        }
        if (f)
            gd *= i;
        if (gd > m)
            break;
        arr[i] = gd;
    }
    int ans = 0, k = m % mod;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
        {
            k = (k * ((m / arr[i]) % mod)) % mod;
        }
        else
            k = 0;
        ans = (ans + exp(m % mod, i) - k + mod) % mod;
    }
    cout << ans << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--)
        code();
    return 0;
}