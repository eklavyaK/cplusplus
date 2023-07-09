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
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int j=0;j<m;j++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int vis[n+1]{};
    function<void(int)> dfs = [&](int node){
        vis[node] = 1;
        for(auto i : graph[node]){
            if(!vis[i.F]) dfs(i.F);
        }
    };
    dfs(1);
    if(!vis[n]){
        cout<<"inf"<<endl;
        return;
    }
    set<pair<int,int>> st;
    st.insert({0,n});
    vector<int> dist(n+1,1e18);
    dist[n] = 0;
    while(!st.empty()){
        auto [d,node] = *st.begin();
        st.erase({d,node});
        for(auto [u,w] : graph[node]){
            if(dist[u]>d+w){
                st.erase({dist[u],u});
                dist[u] = d+w;
                st.insert({dist[u],u});
            }
        }
    }
    debug(dist);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({dist[i+1],i+1});
    }
    sort(v.begin(),v.end());
    debug(v);
    vector<pair<string,int>> ans;
    int time = 0, cnt = 0, i = 0;
    string s = string(n,'1');
    while(i<n && v[i].F==time){
        s[v[i].S-1] = '0';
        i++;
    }
    for(;i<n && cnt<n*n && s[0]=='1';i++){
        v[i].F;
        cnt++;
        ans.push_back({s,v[i].F-time});
        s[v[i].S-1] = '0';
        while(i+1<n && v[i+1].F==v[i].F){
            i++; s[v[i].S-1] = '0';
        }
        time = v[i].F;
    }
    cout<<time<<" "<<cnt<<endl;
    for(auto i : ans) cout<<i.F<<' '<<i.S<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}