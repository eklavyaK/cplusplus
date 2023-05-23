#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

void print(bool z){
    z?cout<<"YES"<<endl:cout<<"NO"<<endl;
}

void code(){
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(n+1);
    int indeg[n+1]{}, done[n+1]{};
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        indeg[u]++,indeg[v]++;
    }
    ld k = sqrt((ld)n), z = 0;
    vector<bool> core(n+1);
    for(int i=1;i<=n;i++){
        core[i]=indeg[i]==4;
        z+=core[i];
        if(!core[i]&&indeg[i]!=2){
            print(0); return;
        }
    }
    if(k!=(int)k || (k+1)*k!=m || k!=z){
        print(0); return;
    }
    int c = 0, f = 0;
    function<void(int)> dfs = [&](int node){
        done[node] = 1; ++c;
        for(auto i : graph[node]){
            if(core[i]){
                if(node!=f && i!=f) c = -3e5;
                continue;
            }
            else if(done[i]) continue;
            else dfs(i);
        }
    };
    for(int i=1;i<=n;i++){
        if(core[i]){
            f = i, c = 0;
            dfs(i);
            if(c!=k){
                print(0); return;
            }
        }
    }
    function<void(int)> corecircle = [&](int node){
        core[node] = 0; ++c;
        for(auto i : graph[node]){
            if(core[i])corecircle(i);
        }
    };
    c=0;
    corecircle(f);
    if(c!=k) print(0);
    else print(1);
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}