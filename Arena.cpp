#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif


const int N = 505, mod = 998244353;
int f[N][N], e[N][N], dp[N][N];
void BC(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i)f[i][j]=1;
            else f[i][j] = (f[i-1][j-1]+f[i-1][j])%mod;
        }
    }
}
void EXP(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j==0) e[i][j] = 1;
            else e[i][j] = e[i][j-1] * i % mod;
        }
    }
}
void code(int TC){
    int n, x; cin>>n>>x;
    "dp[i][j] is basically number of initial configurations of the array which leads to exactly one configuration such that: i non-zero elements are left after a total of j subtractions";
    dp[n][0] = 1;     
    for(int i=n;i>1;i--){
        for(int j=0;j<=x;j++){
            if(j+i-1>=x){
                dp[0][x] = (dp[0][x] + dp[i][j] * f[i][0] * e[x-j][i]) % mod;
                continue;
            }
            for(int k=i;k>=0;k--){
                dp[k][j+i-1] = (dp[k][j+i-1] + dp[i][j] * f[i][k] % mod * e[i-1][i-k]) % mod;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=x;i++) ans += dp[0][i];
    cout<<ans % mod<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; BC(N-5); EXP(N-5);
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}