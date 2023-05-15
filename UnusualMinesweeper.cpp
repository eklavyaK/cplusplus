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
    vector<pair<int,pair<int,int>>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>arr[i].S.F>>arr[i].S.S;
    }
    sort(arr.begin(),arr.end());
    vector<int> par(n), sz(n,1);
    iota(par.begin(),par.end(),0);
    function<int(int)> get_par = [&](int node){
        if(par[node]==node) return node;
        else return par[node] = get_par(par[node]);
    };
    function<void(int,int)> merge = [&](int u, int v){
        u = get_par(u), v = get_par(v);
        if(u!=v){
            if(sz[v]>sz[u]) swap(u,v);
            par[v] = u; sz[u]+=sz[v];
        }
    };
    map<int,int> mx, my;
    for(int i=0;i<n;i++){
        if(mx.count(arr[i].F) && abs(arr[i].S.F-arr[mx[arr[i].F]].S.F)<=k) merge(i,mx[arr[i].F]);
        if(my.count(arr[i].S.F) && abs(arr[i].F-arr[my[arr[i].S.F]].F)<=k) merge(i,my[arr[i].S.F]);
        mx[arr[i].F] = i, my[arr[i].S.F] = i;
    }
    map<int,int> m;
    for(int i=0;i<n;i++){
        int p = get_par(i);
        if(!m.count(p)) m[p] = arr[i].S.S;
        else m[p] = min(m[p],arr[i].S.S);
    }
    vector<int> f;
    for(auto i : m) f.push_back(i.S);
    sort(f.begin(),f.end()); 
    n = f.size();
    int ans = n-1;
    for(int i=0;i<n;i++){
        ans = min(ans,max(f[i],max(0ll,n-i-2)));
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}