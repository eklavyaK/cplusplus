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



const int n = 1e6+5;

void code(int TC){
    int dp[n+5][2],j;
    dp[j][0] = dp[j][0]*3;
    if(j+1<n+2) dp[j][0] += dp[j+1][1];
    if(j-1>=0) dp[j][1] = dp[j-1][1]*3;
    if(j-2>=0) dp[j][1] += dp[j-2][0];

}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}