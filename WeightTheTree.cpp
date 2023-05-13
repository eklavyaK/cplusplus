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
    vector<vector<int>> tree(n+1);
    vector<int> indeg(n+1), par(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        indeg[u]++,indeg[v]++;
    }
    if(n==2){
        cout<<"2 2\n1 1"<<endl;
        return;
    }
    function<void(int)> dfs = [&](int node){
        for(auto i : tree[node]){
            if(i==par[node]) continue;
            par[i] = node;
            dfs(i);
        }
    };
    dfs(1);
    queue<int> q;
    int f[n+1][2],s[n+1][2];
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    for(int i=2;i<=n;i++) if(indeg[i]==1) q.push(i);
    vector<vector<pair<int,int>>> choose(n+1);
    while(!q.empty()){
        int node = q.front(); q.pop();
        s[node][0]++;
        s[node][1]+=tree[node].size();
        f[node][1]++;
        if(par[node]==0)break;
        f[par[node]][1]+=f[node][0];
        s[par[node]][1]+=s[node][0];
        int k = f[node][0]>f[node][1]?0:1;
        if(f[node][0]==f[node][1]) k = s[node][0]>s[node][1]?1:0;
        f[par[node]][0]+=f[node][k];
        s[par[node]][0]+=s[node][k];
        choose[par[node]].push_back({node,k});
        indeg[par[node]]--;
        if(indeg[par[node]]==1 && par[node]!=1) q.push(par[node]);
        else if(indeg[par[node]]==0) q.push(par[node]);
    }
    int k = f[1][0]>f[1][1]?0:1;
    if(f[1][0]==f[1][1]) k = s[1][0]>s[1][1]?1:0;
    vector<int> ans(n+1,1);
    function<void(int,int)> construct = [&](int node, int choice){
        for(auto [i,j] : choose[node]){
            if(i==par[node]) continue;
            if(choice) {
                construct(i,0);
                continue;
            }
            else if(j) ans[i] = tree[i].size();
            construct(i,j);
        }
    };
    ans[1] = k?tree[1].size():1;
    construct(1,k);
    cout<<f[1][k]<<' '<<s[1][k]<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}