#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int w = 0;
void code(){
    w++;
    int n,m; cin>>n>>m;
    vector<bool> ans(m);
    vector<int> u(m),v(m);
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i];
        graph[u[i]].push_back({v[i],i});
        graph[v[i]].push_back({u[i],i});
    }
    set<int> id;
    int vis[n+1]{},indeg[n+1]{};
    function<void(int)> dfs = [&](int node){
        vis[node] = 1;
        for(auto [i,x] : graph[node]){
            if(!vis[i]) ans[x]=1,indeg[i]++,indeg[node]++,dfs(i);
            else if(!ans[x]) id.insert(x);
        }
    };
    dfs(1);
    function<void()> print = [&](){for(auto i : ans)cout<<i;cout<<endl;};
    function<bool(set<int>)> check = [&](set<int> curr){
        int i = *curr.begin(); curr.erase(i);
        set<int> next;
        for(auto k : curr) next.insert(u[k]),next.insert(v[k]);
        if(next.count(u[i])&&next.count(v[i])&&next.size()==3) return false;
        return true;
    };
    if(m-n<2||check(id)){
        print(); return;
    }
    vector<int> done(m);
    int cnt = 0, idx = 0;
    function<bool(int)> dfs1 = [&](int node){
        vis[node] = 1;
        for(auto [i,x] : graph[node]){
            if(!ans[x])continue;
            if(!vis[i]){
                done[x] = 1;
                if(dfs1(i)) return true;
            }
            else if(!done[x]){
                ans[x] = 0, idx = x;
                return true;
            }
        }
        return false;
    };
    function<void(int)> count = [&](int node){
        cnt++; vis[node] = 1;
        for(auto [i,x] : graph[node]){
            if(!ans[x])continue;
            if(!vis[i])count(i);
        }
    };
    for(auto j : id){
        done.clear();
        done.resize(m);
        fill(vis,vis+n+1,0);
        ans[j] = done[j] = 1;
        vis[u[j]] = vis[v[j]] = 1;
        if(dfs1(v[j])){
            fill(vis,vis+n+1,0);
            cnt = 0; count(v[j]);
            if(cnt==n)break;
            ans[idx] = 1;
        }
        ans[j] = 0;
    }
    print();
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}