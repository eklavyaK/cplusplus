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


void code(int TC){
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u, v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int dep[n+1]{};
    function<void(int,int)> dfs = [&](int node, int par){
        for(auto i : tree[node]){
            if(par==i) continue;
            dep[i] = dep[node] + 1;
            dfs(i,node);
        }
    };
    dfs(1,0);
    int curr = 0, f = 1, l = 1, r = 1;
    for(int i=1;i<=n;i++) if(dep[i]&f) curr++;
    if(curr>n-curr) curr = n-curr, f^=1;
    int checker[n+5]{};
    for(int i=0;i<20;i++){
        if((1<<i) & curr){
            for(int j=0;j<(1<<i);j++){
                checker[j+(1<<i)] = 1;
            }
        }
    }
    debug(curr);
    debugarr(checker,n+5);
    debugarr(dep,n+1);
    debug(f);
    for(int i=1;i<=n;i++){
        if((dep[i]&1)==f){
            while(!checker[r]) r++;
            cout<<r++<<" ";
        }
        else{
            while(checker[l]) l++;
            cout<<l++<<" ";
        }
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}