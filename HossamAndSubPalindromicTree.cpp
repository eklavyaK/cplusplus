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
    string s; cin>>s;
    vector<int> dep(n);
    vector<vector<int>> tree(n);
    vector<vector<int>> par(n,vector<int>(15));
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    function<void(int)> parentise = [&](int node){
        for(int i=1;i<15;i++){
            par[node][i] = par[par[node][i-1]][i-1];
        }
        for(auto i : tree[node]){
            if(par[node][0]==i) continue;
            par[i][0] = node;
            dep[i] = dep[node]+1;
            parentise(i);
        }
    };
    parentise(0);
    function<int(int,int)> lca = [&](int u,int v){
        if(dep[v]>dep[u]) swap(u,v);
        int diff = dep[u]-dep[v];
        for(int i=14;i>=0;i--){
            if((1<<i)&diff) u = par[u][i];
        }
        if(u==v) return u;
        for(int i=14;i>=0;i--){
            if(par[u][i]!=par[v][i]){
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    };
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n;i++) dp[i][i] = 1;
    function<int(int,int)> compute_linear = [&](int u, int v){
        if(dp[u][v]) return dp[u][v];
        if(dep[v]>dep[u]) swap(u,v);
        int len = dep[u]-dep[v];
        if(len==1 && s[u]==s[v]) return 2ll;
        else if(len<=1) return 1ll;
        int l = u, r = par[u][0]; len--;
        for(int i=0;i<15;i++){
            if((1<<i)&len) l = par[l][i];
        }
        if(!dp[l][u]) dp[l][u] = dp[u][l] = compute_linear(u,l);
        if(!dp[v][r]) dp[v][r] = dp[r][v] = compute_linear(r,v);
        if(!dp[r][l]) dp[r][l] = dp[l][r] = compute_linear(r,l);
        dp[u][v] = dp[v][u] = max({dp[l][u],dp[v][r],dp[r][l]+(s[u]==s[v])*2});
        return dp[u][v];
    };
    function<int(int,int,int)> compute = [&](int u, int v, int lc){
        if(dp[u][v]) return dp[u][v];
        if(u==lc) return compute_linear(v,lc);
        if(v==lc) return compute_linear(u,lc);
        int l = par[u][0], r = par[v][0];
        if(!dp[u][r]) dp[u][r] = dp[r][u] = compute(r,u,lc);
        if(!dp[l][v]) dp[l][v] = dp[v][l] = compute(l,v,lc);
        if(!dp[l][r]) dp[l][r] = dp[r][l] = compute(r,l,lc);
        dp[u][v] = dp[v][u] = max({dp[l][v],dp[r][u],dp[l][r]+(s[u]==s[v])*2});
        return dp[u][v];
    };
    int ans = 1;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int lc = lca(i,j);
            dp[i][lc] = dp[lc][i] = compute_linear(lc,i);
            dp[j][lc] = dp[lc][j] = compute_linear(lc,j);
            dp[i][j] = dp[j][i] = compute(i,j,lc);
            ans = max(dp[i][j],ans);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}