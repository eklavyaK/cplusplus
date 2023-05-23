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
    int arr[n+1], done[n+1]{}, par[n+1]{}, value[n+1]{};
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    set<pair<int,int>> st[n+1];
    iota(par,par+n+1,0);
    function<int(int)> get = [&](int node){
        if(par[node]==node) return node;
        return par[node] = get(par[node]);
    };
    function<bool(int)> go = [&](int node){
        st[node].insert({arr[node],node});
        int c = 0;
        while(!st[node].empty()){
            auto [str,nd] =*st[node].begin();
            if(done[nd]){
                st[node].erase({str,nd});
                continue;
            }
            if(str>c) break;
            else ++c, done[nd] = 1, par[nd] = node;
            for(auto i : graph[nd]){
                if(!done[i]) st[node].insert({arr[i],i});
                else if(get(i)!=node){
                    st[node].insert(st[par[i]].begin(),st[par[i]].end());
                    st[par[i]].clear();
                    c+=value[par[i]];
                    par[i] = par[par[i]] = node;
                }
            }
            st[node].erase({str,nd});
        }
        value[node] = c;
        return c==n;
    };
    for(int i=1;i<=n;i++){
        if(!arr[i]&&!done[i]&&go(i)){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}