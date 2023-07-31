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
Dinic's max flow algorithm runs in O(V^2 * E) which is faster than O(E^2 * V) of Elmond's Karp algorithm

APPROACH:
    1. First we construct a level graph using bfs (basically we try to find the shortest depth of every node from the source, here capacity is not considered as edge length, the edge length is 1), to construct we assign the level of the forward edges with one higher level than current node, if they already have a lower level then we leave them as it is. We only assign the level to a node adjacent to that node and has available capacity > 0. The use of the level graph is that it while pushing the flow, to through a path we only tend to reach a higher level, which prevents unnecessary dfs transversals during dfs phase. we check whether a level is assigned to the sink or not, if not then algorithm terminates because a path with positive flow is not available to sink.

    2. After constructing a level graph we run a dfs to push the flow through a path (every successive path has one higher level) in the level graph until sink is found, if sink is found in a path, we take the minimum of all the capacities in that path and subtract with available capacities of each edge in that path, and simultaneously we add that minimum capacity to the every back edge corresponding to each edge in the path. Why we add the flow to the back edge? Because it might be possible that the path which we chose doesn't optimize the the maximum flow, so back edge is added to return the flow back, better explanation can be found at: https://drive.google.com/file/d/1Cc35RxPmQ7_pgyIqhnpX4pF7qojNvBrt/view?usp=sharing

    3. There might be possibility that a path in the level graph reaches to a dead end (there is no forward edge post dead end), and if we don't trim that dead end we end up reaching that dead end again thereby increasing the iterations. To avoid that situation, we could simply keep an index pointer at each node and increase it every time after sending a dfs call to next node, i.e. for example a node has 4 adjacent nodes with higher level and positive capacity, so on reaching that node we would send 4 dfs calls to from that node hoping that one of the paths reach the sink. If first dfs reach to a dead end then we increase the id of the node by 1(means on reaching the node again we'd not make a dfs call towards the first adjacent node again), same goes for all the adjacent nodes. This is necessary because it might be possible that all those 4 adjacent nodes reach to a dead end and we might have to return empty handed from that node to previous level and in future if this node is reached again from the previous level from a different parent node, we'd be making all those 4 unnecessary dfs calls again. If we maintain an external index for each node, then it'll simply return without making a single unnecessary dfs call, because index will already be 5.

    4. When a path to sink is found, the edges in that path are decreased with minimum capacity and back edges are increased with the same calacity. And the dfs algorithm terminates

    This whole process is repeated again till the level graph has no level assigned to the sink (no path with positive capacity exists to sink).

CORRECTNESS:
    Since after all the bfs calls a blocking flow is reached, there is no path to sink with positive capacity exists, we can be certain that no more flow can be pushed to the network

COMPLEXITY ANALYSIS:
    Maximum number phases the algorithm could go: (V)
        We could see that in every phase a forward edge from a node is getting saturated, i.e. a forward edge from a node is getting blocked. This algorithm cannot go more than V = number of nodes. To make it more clear, after all the phases we can simply divide the graph into 2 subgraphs connected by only those edges who are saturated (also called minimum cut), one subgraph will have all the edges where those edges start and land into the next subgraph and the sum of all the edges will be equal to max flow. Notice that each such edge will emerge from a node in 1st subgraph. So total number of phases is indeed V. One could argue that many of such edge might emerge from one node in 1st subgraph. In that case we could just merge those edge into 2nd subgraph and chose an previous edge forward edge landing onto the node from which many forward edges of saturated capacity emerge.

    The complexity of dfs in each phase: (E*V)
        As mentioned in step 3, from a node maximum number of dfs calls which can be made is equal to number of edges emerging from it. So worst case time complexity is = number of nodes * number of edges (this can happen if there is direct edge from source to sink and that is the only edge)

    Worst case complexity O(V^2 * E)
*/


ll dinic(vector<vector<pair<ll,ll>>> T, ll n, ll src, ll snk){
    if(src > n || snk > n || src <=0 || snk <= 0) return 0ll;
    vector<vector<bool>> I(n+5,vector<bool>(n+5));
    vector<vector<ll>> p(n+5,vector<ll>(n+5,-1));
    vector<vector<pair<ll,ll>>> G(n+5);
    vector<ll> L(n+5), id(n+5);
    for(ll u=1;u<=n;u++){
        for(ll j=0;j<(ll)T[u].size();j++){
            auto [v,cap] = T[u][j];
            if(p[u][v] == -1) p[u][v] = (ll) G[u].size(), p[v][u] = (ll) G[v].size(), G[u].push_back({v,0}), G[v].push_back({u,0});
            G[u][p[u][v]].second += cap, I[u][v] = G[u][p[u][v]].second > 0;
        }
    }
    auto bfs = [&](){
        L.assign(n+5,-1), L[src] = 0;
        queue<ll> q; q.push(src);
        while(!q.empty()){
            ll u = q.front(); q.pop();
            for(auto [v,c] : G[u]) if(c > 0 && L[v] == -1) L[v] = L[u] + 1, q.push(v);
        }
        return L[snk] != -1;
    };
    function<ll(ll,ll)> dfs = [&](ll u, ll pushed){
        if(u == snk) return pushed;
        for(;id[u] < (ll) G[u].size();id[u]++){
            auto [v, c] = G[u][id[u]];
            if(L[v] != L[u] + 1 || c <= 0) continue;
            if(ll flo = dfs(v, min(pushed, c))){
                G[u][id[u]].second -= flo, G[v][p[v][u]].second += flo;
                return flo;
            }
        }
        return 0ll;
    };
    ll maxflo = 0;
    if(snk == src) return -1ll;
    while(bfs()) id.assign(n+5,0), maxflo += dfs(src,8e18);
    
    "To find MIN CUT EDGES we vist all the nodes from the source such that these nodes are connected to source with a sequence of positive flow in RESIDUAL graph (obtained after the last bfs), visited and unvisited nodes will form two subgraphs, nodes connecting the subgraphs must be saturated, so their residual cap is 0, after this we just check if a edge connects a visited node and an unvisited node and it EXISTED in the initial graph with positive cap, then it will be a min cut edge";
    // id.assign(n+5,0); vector<pair<int,int>> edges;
    // function<void(int)> add = [&](int u){
    //     id[u] = 1;
    //     for(auto [v,c] : G[u]) if(!id[v] && c>0) add(v);
    // };
    // add(src);
    // for(int u=1;u<=n;u++) if(id[u]) for(auto [v,c] : G[u]) if(!id[v] && I[u][v]) edges.push_back({u,v});
    
    "To find maximum number of DISJOINT PATHS we just simply begin from source and go along the path which EXISTED in original graph with a positive cap and got vanished (cap is reduced to 0) after pushing the flow, we'are sure to find a distinct path (no edges are common) along it because if two paths have a common edge one of them shuouldn't exist";
    // id.assign(n+5,0); vector<int> path;
    // function<void(int)> go = [&](int u){
    //     path.push_back(u);
    //     if(u == snk){
    //         cout<< endl << (int) path.size() << endl;
    //         for(auto i : path) cout<< i << " ";
    //         return;
    //     }
    //     for(;id[u] < (int)G[u].size();id[u]++){
    //         auto [v,c] = G[u][id[u]];
    //         if(I[u][v] && c<=0){
    //             I[u][v] = 0, go(v);
    //             path.pop_back();
    //             if(u != src) return;
    //         }
    //     }
    // };
    // go(src);
    
    return maxflo;
}

void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> G(n+5);
    for(int i=0;i<m;i++){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});
    }
    cout<<dinic(G,n,1,n);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    ll TT = 1;
    for (ll TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}