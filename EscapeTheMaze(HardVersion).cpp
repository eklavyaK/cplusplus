#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int inf = 200005;

void code(){
    int n,k; cin>>n>>k;
    vector<vector<int>> tree(n+1);
    vector<int> block(n+1),indeg(n+1),dist(n+1,inf);
    while(k--){
        int t; cin>>t;
        dist[t] = 0;
    }
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        indeg[u]++;indeg[v]++;
    }
    vector<int> dep(n+1), par(n+1);
    function<void(int)> dfs = [&](int node){
        for(auto i : tree[node]){
            if(par[node]==i)continue;
            dep[i]=dep[node]+1;
            par[i] = node;
            dfs(i);
        }
    };
    dfs(1);
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(indeg[i]==1)q.push(i);
    }
    vector<int> curr = indeg;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(dist[node]<=dep[node])block[node] = 1;
        indeg[par[node]]--;
        dist[par[node]]=min(dist[par[node]],dist[node]+1);
        if(indeg[par[node]]==1 && node!=1)q.push(par[node]);
        if(indeg[par[node]]==0)q.push(par[node]);
    }
    int ans = 0; 
    bool f = true;
    function<void(int)> check = [&](int node){
        if(block[node]){
            ans++;
            return;
        }
        else if(curr[node]==1 && node!=1)f = false;
        for(auto i : tree[node]){
            if(par[node]!=i)check(i);
        }
    };
    check(1);
    if(f)cout<<ans<<endl;
    else cout<<-1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}