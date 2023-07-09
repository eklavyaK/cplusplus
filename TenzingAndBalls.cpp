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


int inf = 1e9;


void code(int TC){
    int n; cin>>n;
    vector<int> c(n+1,-inf),arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> dp(n,0),is(n+1);
    dp[0] = 0;
    is[arr[0]] = 1;
    c[arr[0]] = 1;
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1],(c[arr[i]]+i)*is[arr[i]]);
        c[arr[i]] = max(c[arr[i]],dp[i-1]-(i-1));
        debug(c[arr[i]]);
        is[arr[i]] = 1;
    }
    debug(dp);
    cout<<dp[n-1]<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}