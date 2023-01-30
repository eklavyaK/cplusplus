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
    vector<int> c(n);
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int par[n+1]{};
    par[c[0]] = -1;
    function<void(int)> dfs = [&](int node){
        for(auto i : tree[node]){
            if(i!=par[node]){
                par[i] = node;
                dfs(i);
            }
        }
    };
    dfs(c[0]);
    vector<int> best(n+1,n);
    best[c[0]] = 0;
    int ans = 1e9;
    for(int i=1;i<n;i++){
        int node = c[i];
        int dist = 0;
        while(node>0 && ans>dist){
            ans = min(ans,best[node]+dist);
            best[node] = min(best[node],dist);
            node = par[node];
            dist++;
        }
        cout<<ans<<" ";;
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}