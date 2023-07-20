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


const int N = 2e5+5;
int p[N][35];

void code(int TC){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>p[i][0];
    for(int i=1;i<35;i++){
        for(int j=1;j<=n;j++) p[j][i] = p[p[j][i-1]][i-1];
    }
    while(q--){
        int u,k; cin>>u>>k;
        for(int i=0;i<35;i++){
            if((1ll<<i)&k) u = p[u][i];
        }
        cout<<u<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}