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





void code(int TC){
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    bool sym[n+1]{};
    int par[n+1]{}, hash[n+1]{}, now = 1;
    map<vector<int>,int> is;
    function<void(int)> dfs = [&](int node){
        vector<int> cur;
        map<int,int> checker;
        for(auto i : tree[node]){
            if(i==par[node]) continue;
            par[i] = node;
            dfs(i);
            checker[hash[i]]++;
            cur.push_back(hash[i]);
        }
        sort(cur.begin(),cur.end());
        debug(cur,checker);
        if(!is.count(cur)) is[cur] = now++;
        hash[node] = is[cur];
        int b = 0, hashh = 0;
        for(auto [k,c] : checker){
            if(c & 1){
                debug(k,b);
                if(b){
                    sym[node] = 0;
                    return;
                }
                else hashh = k, b = 1;
                debug(hashh,b);
            }
        }
        debug(node);
        debug(b,hashh);
        if(b){
            for(auto i : tree[node]){
                if(i==par[node]) continue;
                debug(i,hashh,hash[i],sym[i]);
                if(hashh==hash[i] && sym[i]){
                    sym[node] = 1;
                    return;
                }
            }
            sym[node] = 0;
        }
        else sym[node] = 1;
    };
    dfs(1);
    debugarr(sym,n+1);
    cout<<(sym[1]?"YES":"NO")<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}