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


const int N = 5005, inf = 5005;
vector<int> tree[N], ans(N), vis(N), dis(N,inf);
int n;
void bfs(int node){
    dis[node] = 0;
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto node : tree[u]){
            if(vis[node]) continue;
            vis[node] = 1;
            dis[node] = dis[u]+1;
            q.push(node);
        }
    }
    sort(dis.begin(),dis.end());
    for(int i=0;i<n;i++){
        dis[i] += dis[i-1*(i!=0)];
        ans[i+1] = max(ans[i+1],(n-1)*(i+1)-2*dis[i]);
    }
    fill(vis.begin(),vis.end(),0);
    fill(dis.begin(),dis.end(),inf);
}

void code(int TC){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=n;i++) bfs(i);
    for(int i=0;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}