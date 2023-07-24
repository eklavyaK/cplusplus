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
#define debugarr(a,n) 42
#define debug(...) 42
#endif

/*
Hamiltonian walk is way of transversing a graph where we tend to visit each and every node exactly node

It is a np problem with complexity or around O(n^2 * 2^n), which can be minimised using various constraints

APPROACH:
    we generally solve it using bitmasking + dp
    the mask as set bits for the nodes which have been visited exactly once
    dp[mask][i] = number of ways to visit each nodes in the mask exactly once where last visited node is i (i is a position of a set bit)
    to calculate dp[mask][i], we sum the number of ways from which dp[mask][i] has been formed
    so initially mask was equal to mask' = mask - (1<<i)
    in mask' we check for every set bit j which can lead to mask
    for that there must be an edge from j to i,
    so dp[mask][i] = sigma( dp[mask'][j] * [G[j][i] && (mask'^(1<<i) == mask)]) for all j from 0 to n-1
*/
const int M = 1e9+7;
int dp[20][1<<20];
vector<int> E[20];
int add(int A){
    if(A>=M) A-=M;
    return A;
}
void code(int TC){
    int n,m; cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v; u--, v--;
        E[v].push_back(u);
    }
    dp[0][1] = 1;
    for(int i=3;i<(1<<n);i+=2){
        for(int v=1;v<n;v++) if((1<<v)&i){
            for(auto u : E[v]) dp[v][i] = add(dp[v][i] + dp[u][i^(1<<v)]);
        }
    }
    cout<<dp[n-1][(1<<n)-1];
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}