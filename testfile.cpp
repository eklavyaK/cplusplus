#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int mod = 1000000007; long long result = 1l;
        for(int i = 1; i<=n; i++) {
            int r_factorial = 1;for(int j = 2; j<=i; j++) r_factorial*=j;
            for(int j = 0; j<=n; j++) {
                
            }
        }
    }
    return 0;
}