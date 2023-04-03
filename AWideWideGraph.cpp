#include<bits/stdc++.h>
//#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    int indeg[n+1]{}, par[n+1]{};
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        indeg[u]++;indeg[v]++;
    }
    function<void(int)> parentise = [&](int node){
        for(auto i : tree[node]){
            if(i!=par[node]) par[i] = node, parentise(i);
        }
    };
    parentise(1);
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(indeg[i]==1)q.push(i);
    }
    vector<vector<pair<int,int>>> v(n+1,vector<pair<int,int>>(2));
    for(int i=1;i<=n;i++) v[i][0].S=i,v[i][1].S=i;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(v[par[node]][0].F<v[node][1].F+1){
            v[par[node]][0].F = v[node][1].F+1;
            v[par[node]][0].S = v[node][1].S;
            sort(v[par[node]].begin(),v[par[node]].end());
        }
        indeg[par[node]]--;
        if(indeg[par[node]]==1 && par[node]!=1)q.push(par[node]);
    }
    int mx = 0, en[2]{};
    for(int i=1;i<=n;i++){
        if(v[i][0].F+v[i][1].F>mx){
            mx = v[i][0].F+v[i][1].F, en[0] = v[i][0].S, en[1] = v[i][1].S;
        }
    }
    vector<vector<pair<int,int>>> dist(2,vector<pair<int,int>>(n+1));
    for(int i=1;i<=n;i++)dist[0][i].S = dist[1][i].S = i;
    function<void(int,int,int)> dfs = [&](int node, int id, int p){
        for(auto i : tree[node]){
            if(!dist[id][i].F && p!=i) dist[id][i].F = dist[id][node].F+1, dfs(i,id,node);
        }
    };
    dfs(en[0],0,0);
    dfs(en[1],1,0);
    sort(dist[0].begin(),dist[0].end(),greater<pair<int,int>>());
    sort(dist[1].begin(),dist[1].end(),greater<pair<int,int>>());
    vector<int> ans(n), done(n+1);
    int l = 0, r = 0, cnt = n+1;
    for(int i=mx+1;i<=n;i++)ans[i-1] = n;
    for(int i=mx;i>=1;i--){
        while(l<n-1 && dist[0][l].F>i)l++;
        while(l<n-1 && dist[0][l].F==i){if(!done[dist[0][l].S])cnt--,done[dist[0][l].S]=1;l++;}
        while(r<n-1 && dist[1][r].F>i)r++;
        while(r<n-1 && dist[1][r].F==i){if(!done[dist[1][r].S])cnt--,done[dist[1][r].S]=1;r++;}
        ans[i-1] = cnt;
    }
    for(auto i : ans)cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}