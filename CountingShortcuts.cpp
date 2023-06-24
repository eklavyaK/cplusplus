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

int inf = 1e9, mod = 1e9+7;

void code(int TC){
    int n,m; cin>>n>>m;
    int s,t; cin>>s>>t;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int> c(n+1,inf);
    c[t] = 0;
    q.push({0,t});
    bool done[n+1]{};
    while(!q.empty()){
        auto [d, node] = q.top(); q.pop();
        if(done[node]) continue;
        else done[node] = 1;
        for(auto i : graph[node]){
            if(c[i]>d+1){
                c[i] = d+1;
                q.push({c[i],i});
            }
        }
    }
    debug(c);
    vector<vector<int>> new_graph(n+1);
    int indeg[n+1]{}, outdeg[n+1]{};
    queue<int> qq;
    qq.push(s);
    fill(done,done+n+1,0);
    while(!qq.empty()){
        int node = qq.front(); qq.pop();
        for(auto i : graph[node]){
            if(c[i]==c[node]-1){
                new_graph[i].push_back(node);
                new_graph[node].push_back(i);
                debug(make_pair(i,node));
                if(!done[i])qq.push(i), done[i] = 1;
                indeg[i]++;
            }
        }
    }
    int waysf[n+1]{}, waysb[n+1]{};
    waysf[s] = 1;
    qq.push(s);
    while(!qq.empty()){
        int node = qq.front(); qq.pop();
        for(auto i : new_graph[node]){
            if(c[i]==c[node]-1){
                waysf[i] = (waysf[i] + waysf[node]) % mod;
                indeg[i]--;
                if(!indeg[i]) qq.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(auto u : graph[i]){
            if(c[i]==c[u]-1) outdeg[u]++;
        }
    }
    waysb[t] = 1;
    qq.push(t);
    while(!qq.empty()){
        int node = qq.front(); qq.pop();
        for(auto i : graph[node]){
            if(c[i]==c[node]+1){
                waysb[i] = (waysb[i] + waysb[node]) % mod;
                outdeg[i]--;
                if(!outdeg[i]) qq.push(i);
            }
        }
    }
    int ans = waysf[t];
    debug(ans);
    for(int i=1;i<=n;i++){
        for(auto u : graph[i]){
            if(c[i]==c[u]) ans += waysb[u]*waysf[i] % mod;
        }
    }
    cout<<ans % mod<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}