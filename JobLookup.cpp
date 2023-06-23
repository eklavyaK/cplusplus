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

const int N = 205, inf = 1e18;
int dp[N][N][N], c[N][N], s[N][N], par[N];

int calc(int l, int r, int node, int cost){
    if(r<l) return 0;
    int left = 0, right = 0;
    for(int i=l;i<node;i++){
        if(dp[l][node-1][i]==-1) dp[l][node-1][i] = calc(l,node-1,i,cost+s[l][node-1]);
        if(!left) left = dp[l][node-1][i];
        else left = min(left,dp[l][node-1][i]);
    }
    for(int j=node+1;j<=r;j++){
        if(dp[node+1][r][j]==-1) dp[node+1][r][j] = calc(node+1,r,j,cost+s[node+1][r]);
        if(!right) right = dp[node+1][r][j];
        else right = min(right,dp[node+1][r][j]);
    }
    return left+right+s[l][r];
}
int subtree(int l, int r, int n){
    int sum = 0;
    for(int i=l;i<=r;i++){
        for(int j=1;j<=n;j++){
            if(j<l || j>r) sum+=c[i][j];
        }
    }
    return sum;
}
void construct(int l, int r, int p){
    int mn = inf;
    for(int i=l;i<=r;i++) if(dp[l][r][i]!=-1) mn = min(dp[l][r][i],mn);
    for(int i=l;i<=r;i++){
        if(dp[l][r][i]==mn){
            par[i] = p;
            construct(l,i-1,i);
            construct(i+1,r,i);
        }
    }
}
void code(int TC){
    int n; cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>c[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) s[i][j] = subtree(i,j,n);
    }
    for(int i=1;i<=n;i++) dp[1][n][i] = calc(1,n,i,0);
    for(int i=1;i<=n;i++) debug(dp[1][n][i]);
    construct(1,n,0);
    for(int i=1;i<=n;i++) cout<<par[i]<<' ';cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}