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
Tutorial can be accessed here: https://drive.google.com/file/d/1CacN71mnQrq96_RMgJzsRd734_fmFWDT/view?usp=sharing

Tarjan's way of finding SCC takes little less time complexity than Kosaraju because it runs the dfs only once but since there are many vectors involved it's space complexity is assumed to be same as Kosaraju.
*/

vector<vector<int>> Tarjan(vector<vector<int>> G, int n){
    vector<vector<int>> C; int id = 0;
    vector<int> s, f(n+5), p(n+5), inStack(n+5), vis(n+5);
    function<void(int)> dfs = [&](int u){
        inStack[u] = vis[u] = 1;
        f[u] = p[u] = id = id+1;
        s.push_back(u);
        for(auto v : G[u]){
            if(!vis[v]) dfs(v);
            if(inStack[v]) f[u] = min(f[u],f[v]);
        }
        if(f[u]!=p[u]) return;
        vector<int> cur;
        while(s.back()!=u) cur.push_back(s.back()), inStack[s.back()] = 0, s.pop_back();
        cur.push_back(u), inStack[u] = 0, s.pop_back(), C.push_back(cur);
    };
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    return C;
}

void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<int>> G(n+5);
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    int ans[n];
    auto C = Tarjan(G,n);
    n = C.size();
    debug(C);
    for(int i=0;i<n;i++){
        for(auto j : C[i]) ans[j-1] = i+1;
    }
    cout<<n<<endl;
    for(auto i : ans) cout<<i<<' ';
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}