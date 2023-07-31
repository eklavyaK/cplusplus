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
kosaraju algorithm exploits the fact that all the nodes which belong to a SCC will belong to same SCC in reverse graph.
So we make a reverse graph,
        [1]--->[2]--->[3]<---[4]--->[5]<---[6]<---[7]<---[8]<---[9]  Graph (numbers represent a SCC)
        [1]<---[2]<---[3]--->[4]<---[5]--->[6]--->[7]--->[8]--->[9]  Transpose Graph

If we start dfs from a node in a SCC, then it is sure to visit all the nodes in that SCC as well as all the nodes of a SCC which is connected to the SCC with a forward edge, that's why we need a stack which makes sure all the SCCs are visited in topological order kind of thing.

If look at the above example:
    Assume we started dfs from SCC 8, it visits 6, 7, and 5 in that order. So in stack the 5 will be pushed to bottom and 8 will be top most, now somewhere at some point we'll visit SCC 9 also so it'll be above 8. You can see all the SCCs which can be visited from 8 are surely going to come below it in stack. Reason is whether they've visited before 8 or when we're starting from 8 it makes sure all the remaining SCC which can be visited by it must come under 8 before placing 8 on top of it.
    Now we'll reverse the graph and start the dfs from the top of the stack, i.e we'll dfs SCC 9 first, all the nodes in that SCC will get visited and dfs will end. It won't go to SCC 8 as graph has been reversed. Now pop SCC 9 and start dfs in SCC 8, then same for SCC 7, 6 and finally 5. In this way we'll be able to construct all the possible SCCs.
*/
vector<vector<int>> Kosaraju(vector<vector<int>> G, int n){
    stack<int> comp;
    vector<int> V(n+5), T;
    vector<vector<int>> R(n+5), C;
    for(int u=1;u<=n;u++) for(auto v : G[u]) R[v].push_back(u);
    function<void(int)> dfs = [&](int u){
        V[u] = 1;
        for(auto v : G[u]) if(!V[v]) dfs(v);
        comp.push(u);
    };
    function<void(int,int)> scc = [&](int u, int c){
        V[u] = 0; T.push_back(u);
        for(auto v : R[u]) if(V[v]) scc(v,c);
    };
    int c = 0;
    for(int i=1;i<=n;i++) if(!V[i]) dfs(i);
    while(!comp.empty()){
        int node = comp.top(); comp.pop();
        if(V[node]) T.clear(), scc(node,c++), C.push_back(T);
    }
    return C;
}
 
void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<int>> G(n+5);
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    int ans[n];
    auto C = Kosaraju(G,n);
    n = C.size();
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