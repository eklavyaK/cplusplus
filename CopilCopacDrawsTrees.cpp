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
    int par[n+1]{};
    map<pair<int,int>,int> m;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        m[{min(u,v),max(u,v)}] = i;
    }
    function<void(int,int)> dfs = [&](int node,int parr){
        for(auto i : tree[node]){
            if(parr==i) continue;
            par[i] = node;
            dfs(i,node);
        }
    };
    dfs(1,0);
    queue<int> bfs;
    int ans[n+1]{0};
    for(auto i : tree[1]){
        ans[i] = 1;
        bfs.push(i);
    }
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        for(auto i : tree[node]){
            if(i==par[node]) continue;
            ans[i] = ans[node];
            if(m[{min(node,i),max(node,i)}]<m[{min(node,par[node]),max(node,par[node])}]) ans[i]++;
            bfs.push(i);
        }
    }
    cout<<*max_element(ans,ans+n+1)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}