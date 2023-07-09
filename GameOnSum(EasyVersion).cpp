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


const int mod = 1e9+7, c = 5e8+4;

void code(int TC){
    int n,m,k; 
    cin>>n>>m>>k;
    vector<vector<int>> dp(n+5,vector<int>(m+5,-1));
    function<int(int,int)> calc = [&](int n, int m){
        if(n==m) return k * n % mod;
        if(m==0) return 0ll;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m] = (calc(n-1,m) + calc(n-1,m-1)) * c % mod;
    };
    cout<<calc(n,m)<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}