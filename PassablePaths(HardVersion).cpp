#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    int par[n+1]{}, indeg[n+1]{}, dep[n+1]{};
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        indeg[u]++,indeg[v]++;
    }
    vector<vector<int>> path(n+1);
    int queries; cin>>queries;
    for(int i=1;i<=queries;i++){
        int k; cin>>k;
        while(k--){
            int node; cin>>node;
            path[node].push_back(i);
        }
    }
    queue<int> q;
    for(int i=2;i<=n;i++)if(indeg[i]==1)q.push(i);
    function<void(int)> parentise = [&](int node){
        for(auto i : tree[node]){
            if(i!=par[node]) par[i] = node, dep[i] = dep[node]+1, parentise(i);
        }
    };
    parentise(1);
    set<int> st[n+1];
    int cnt[queries+1]{}, lca[queries+1]{};
    function<void(int,int)> merge = [&](int p, int c){
        if(st[p].size()<st[c].size()){
            for(auto i : st[p]){
                if(st[c].count(i))lca[i] = p;
                else st[c].insert(i);
            }
            st[p].clear();
            swap(st[p],st[c]);
        }
        else{
            for(auto i : st[c]){
                if(st[p].count(i))lca[i] = p;
                else st[p].insert(i);
            }
            st[c].clear();
        }
    };
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto i : path[node]){
            if(st[node].count(i)){
                if(lca[i] && lca[i]!=node)cnt[i]++;
            }
            else st[node].insert(i),cnt[i]++;
        }
        merge(par[node],node);
        indeg[par[node]]--;
        if(indeg[par[node]]==1&&par[node]!=1)q.push(par[node]);
        if(par[node]==1 && !indeg[1])q.push(1);
    }
    for(int i=1;i<=queries;i++){
        if(cnt[i]<=2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t   =   1; while(t--)code();
    return 0;
}