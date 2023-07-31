#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;





void code(int TC){
    int n,m;
    vector<vector<int>> graph(n+1);
    while(m--){
        int u,v;
        graph[u].push_back(v);
    }
    vector<bool> vis(n+1);
    function<void(int)> dfs = [&](int node){
        vis[node] = 1;
        for(auto i : graph[node]){
            if(!vis[i]) dfs(i);
        }
    };
    int mother = 0;
    fill(vis.begin(),vis.end(),0);
    "if dfs run from a vertex can't visit all nodes in the graph then it is not mother, so we choose the best candidate for mother as the vertex which visits the remaining nodes, and finally run a dfs again from the candidate to confirm if it is actually a mother";
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i), mother = i;
    fill(vis.begin(),vis.end(),0);
    dfs(mother);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"MOTHERLESS"<<endl;
            return;
        }
    }
    cout<<mother<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}