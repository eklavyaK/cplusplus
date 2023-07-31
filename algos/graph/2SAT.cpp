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
 
 
const int N = 1e5+5;              //maximum number of nodes
vector<int> ans[2*N];
vector<vector<int>> graph(2*N);  //2 has been multiplied to include 'inclusion' and 'non-inclusion' of a node
vector<vector<int>> revgraph(2*N);
int vis[2*N],order[2*N],n,m,cnt=1;
stack<int> comps;
void dfs(int node){
    vis[node]=1;
    for(auto i : graph[node]){
        if(!vis[i]) dfs(i);
    }
    comps.push(node);
}
void revdfs(int node){
    vis[node]=0;
    ans[cnt].push_back(node);
    for(auto i : revgraph[node]){
        if(vis[i]) revdfs(i);
    }
}
void SCC(){
    for(int v=1;v<=n;v++){
        for(auto u : graph[v])
        revgraph[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    while(!comps.empty()){
        int c = comps.top();
        comps.pop();
        if(!vis[c])continue;
        revdfs(c); cnt++;
    }
}
void add_junction(bool cnfa, int a, bool cnfb, int b){
    if(cnfa){
        if(cnfb){
            graph[n+a].push_back(b);
            graph[n+b].push_back(a);
        }
        else{
            graph[n+a].push_back(n+b);
            graph[b].push_back(a);
        }
    }
    else{
        if(cnfb){
            graph[a].push_back(b);
            graph[n+b].push_back(n+a);
        }
        else{
            graph[a].push_back(n+b);
            graph[b].push_back(n+a);
        }
    }
}
void solve_2SAT(int nodes, int junctions){
    n=nodes;
    while(junctions--){
        char ca,cb; int a,b;
        cin>>ca>>a>>cb>>b;
        bool cnfa = (ca=='-'?false:true);
        bool cnfb = (cb=='-'?false:true);
        add_junction(cnfa,a,cnfb,b);
        //cnfa, cnfb denotes whether a and b are included or not if cnfa is true means a is included same goes for cnfb
    }
    n = nodes*2;
    SCC();
    for(int i=1;i<=n;i++){
        for(auto u : ans[i]){
            order[u]=i;
        }
    }
    n/=2;
    char result[n+1];
    for(int i=1;i<=n;i++){
        if(order[n+i]==order[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        else{
            result[i]=order[n+i]>order[i]?'-':'+';
        }
    }
    for(int i=1;i<=n;i++){
        cout<<result[i]<<' ';
    }
}
 
 
void code(int TC){
    int n,m; cin>>n>>m;
    solve_2SAT(m,n);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}