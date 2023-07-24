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


const int N = 505;  //max nodes
unsigned int pos[N];
int in[N][N],dis[N];
map<int,map<int,int>> check;
vector<pair<int,ll>> graph[N];
int s,f,n,m;ll ans;  //n,m declared
vector<vector<int>> disjpth;
vector<int> track;
int flow[N][N];
bool bfs(){
    fill(dis,dis+n+1,N);
    bool done[n+1]{};
    queue<int> Q; Q.push(s);
    done[s] = 1; dis[s] = 0;
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        for(auto [to, cap] : graph[node]){
            if(!done[to] && cap>0){
                dis[to] = dis[node]+1;
                done[to]=1;Q.push(to);
            }
        }
        if(dis[node]>dis[f])break;
    }
    return done[f];
}
ll dfs(int node, ll flo){
    if(node==f)return flo;
    for(;pos[node]<graph[node].size();pos[node]++){
        auto [u,cap] = graph[node][pos[node]];
        if(dis[u]==dis[node]+1 && cap>0){
            ll c = dfs(u,min(flo,cap));
            if(!c) continue;
            graph[u][in[u][node]].S+=c;
            graph[node][pos[node]].S-=c;
            return c;
        }
    }
    return 0;
}
void Dinic(int start, int final){
    ans = 0;check.clear();
    s = start; f = final;
    for(int i=0;i<m;i++){
        int u, v; ll c; cin>>u>>v>>c;
        flow[u][v]=1;
        if(!check[u].count(v)){
            in[u][v]=graph[u].size();
            graph[u].push_back({v,c});
            in[v][u]=graph[v].size();
            graph[v].push_back({u,0});   //for undirected graph replace the 0 with c
            check[u][v]; check[v][u];
        }
        else{
            graph[u][in[u][v]].S+=c;
        }
    }
    while(bfs()){
        fill(pos,pos+n+1,0);
        for(;pos[s]<graph[s].size();pos[s]++){
            auto [u,cap] = graph[s][pos[s]];
            if(dis[u]==dis[s]+1 && cap>0){;
                ll c = dfs(u,cap);
                if(!c) continue;
                graph[u][in[u][s]].S+=c;
                graph[s][pos[s]].S-=c;
                ans+=c;
            }
        }
    }
    cout<<ans<<endl;           //maximum flow and minimum cut and maximum disjoint paths



    //bool vis[n+1]{};
    //function<void(int)> dfsmincut = [&](int node){
    //	vis[node]=true;
    //	for(auto [u,cap] : graph[node]){
    //		if(!vis[u] && cap>0)
    //			dfsmincut(u);
    //	}
    //};
    //dfsmincut(s);
    //set<pii> st;                //------------------> commented code for finding MINIMUM CUT EDGES
    //for(auto vec : graph){
    //	for(auto [node,cap] : vec){
    //		if(vis[node]){
    //			for(auto [u,_] : graph[node]){
    //				if(!vis[u]){
    //					st.insert({node,u});
    //				}
    //			}
    //		}
    //	}
    //}
    //for(auto [a,b] : st)cout<<a<<' '<<b<<endl;  //edges to be removed



    //fill(pos,pos+n+1,0);
    //bool ok = false;
    //function<void(int)> findpath=[&](int node){
    //	track.push_back(node);
    //	if(node==f){
    //		ok = true;
    //		disjpth.push_back(track);
    //		track.pop_back();
    //		return;
    //	}                      //----------------------------> code to find MAXIMUM DISJOINT EDGES from s to f
    //	for(;pos[node]<graph[node].size();){
    //		auto [u,cap]=graph[node][pos[node]];
    //		if(cap<=0 && flow[node][u]){
    //			pos[node]++;
    //			findpath(u);
    //			if(ok){
    //				if(node==s)ok=false;
    //				else break;
    //			}
    //		}
    //		else pos[node]++;
    //	}
    //	track.pop_back();
    //};
    //findpath(s);
    //for(auto vec : disjpth){
    //	cout<<vec.size()<<endl;
    //	for(auto i : vec)
    //	cout<<i<<' ';cout<<endl;
    //}
}


void code(int TC){
    

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}