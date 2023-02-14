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
    int par[n+1]{}, s[n+1];
    int idg[n+1]{};
    vector<map<int,int>> f(n+1);
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int k;cin>>k;
        par[i+2] = k;
        tree[i+2].push_back(k);
        tree[k].push_back(i+2);
        idg[k]++; idg[i+2]++;
    }
    for(int i=1;i<=n;i++)cin>>s[i];
    function<int(int,int,int)> dfs = [&](int node,int np, int indeg){
        int ans = np*s[node];
        if(!indeg)return ans;
        vector<int> u,v;
        for(auto i : tree[node]){
            if(i==par[node])continue;
            if(!f[i].count(np/indeg)) f[i][np/indeg] = dfs(i,np/indeg,idg[i]-1);
            u.push_back(f[i][np/indeg]);
            ans+=u.back();
        }
        if(!(np%indeg)) return ans;
        for(auto i : tree[node]){
            if(i==par[node])continue;
            if(!f[i].count(np/indeg+1))f[i][np/indeg+1] = dfs(i,np/indeg+1,idg[i]-1);
            v.push_back(f[i][np/indeg+1]);
        }
        int k = u.size();
        for(int i=0;i<k;i++){
            v[i] = v[i]-u[i];
        }
        sort(v.begin(),v.end(),greater<int>());
        k = np%indeg;
        for(int i=0;i<k;i++){
            ans+=v[i];
        }
        return ans;
    };
    cout<<dfs(1,k,idg[1])<<endl;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}