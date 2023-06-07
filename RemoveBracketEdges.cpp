#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(n+1);
    int in[n+1]{},out[n+1]{};
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        in[v]++,out[u]++;
    }
    vector<int> go(n+1,1),done(n+1);
    function<void(int)> dfs = [&](int node){
        done[node] = 1;
        if(out[node]<2)return;
        for(auto i : graph[node]){
            if(!done[i]) dfs(i);
            if(in[i]>1) go[node] = max(go[node],go[i]+1);
        }
    };
    for(int i=1;i<=n;i++){
        if(!done[i]) dfs(i);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,go[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}