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


const int mod = 1e9+7, N = 2000, L = 40;
int dp[2][N][N], pos[N], a[N], n, k, m, x;

void code(int TC){
    int n,k; cin>>n>>k;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int a; cin>>a;
        if(a) pos[m++] = i;
    }
    for(int i=1;i<=n;i++) dp[1-x][i][abs(pos[0]-i)] = 1*(abs(pos[0]-i)<=k);
    for(int i=0;i<=k;i++){
        for(int j=1;j<=n;j++) dp[1-x][j][i] += dp[1-x][j-1][i];
    }
    for(int j=1;j<m;j++){
        int l = j-L<0?1:pos[j-L];
        int r = j+L>m-1?n:pos[j+L];
        for(int used=0;used<=k;used++){
            for(int i=l;i<=r;i++){
                dp[x][i][used] = used-abs(pos[j]-i)>=0?dp[1-x][i-1][used-abs(pos[j]-i)]:0;
                if(i!=l) dp[x][i][used] = (dp[x][i][used] + dp[x][i-1][used]) % mod;
            }
        }
        x = 1 - x;
    }
    int ans = 0;
    for(int i=k;i>=0;i-=2) ans = ans + dp[1-x][n][i];
    cout<<ans % mod<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}