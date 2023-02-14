#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    vector<vector<int>> par(n+1,vector<int>(25));
    vector<set<int>> graph(n+1);
    bool done[n+1]{};
    for(int i=2;i<=n;i++){
        cin>>par[i][0];
        done[par[i][0]]=1;
        graph[par[i][0]].insert(i);
        graph[i].insert(par[i][0]);
    }
    par[1][0] = 1;
    for(int i=1;i<25;i++){
        for(int j=1;j<=n;j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    int dep[n+1]{};
    set<pair<int,int>> st;
    function<int(int)> set_dep = [&](int node){
        if(node==1)return 0ll;
        if(dep[node]) return dep[node];
        return dep[node] = set_dep(par[node][0])+1;
    };
    for(int i=2;i<=n;i++){
        if(!done[i])set_dep(i);
    }
    for(int i=1;i<=n;i++)st.insert({dep[i],i});
    function<bool(int,int)> check = [&](int h, int tot){
        auto s = st;
        auto tree = graph;
        function<void(int)> dfs = [&](int node){
            s.erase({dep[node],node});
            for(auto i : tree[node]){
                if(i==par[node][0])continue;
                dfs(i);
            }
        };
        while(true){
            if(s.empty())return true;
            auto now = *s.rbegin();
            s.erase(now);
            if(now.F<=h)return true;
            else if(!tot)break;
            int up = h - 1;
            int node = now.S;
            for(int i=0;i<25;i++){
                if((1<<i)&up) node = par[node][i];
            }
            tree[node].erase(par[node][0]);
            tree[par[node][0]].erase(node);
            dfs(node);
            tot--;
        }
        return false;
    };
    int l = 1, r = n;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid,k)) r = mid-1;
        else l = mid+1;
    }
    cout<<r+1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}