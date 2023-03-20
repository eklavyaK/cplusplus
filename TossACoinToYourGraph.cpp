#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> graph(n+1);
    vector<int> integer(n+1);
    for(int i=1;i<=n;i++){
        cin>>integer[i];
    }
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    bool ans = false;
    set<int> st;
    vector<bool> done(n+1);
    vector<int> ret(n+1);
    function<void(int,int)> dfs = [&](int node,int mx){
        done[node] = 1;
        if(integer[node]>mx)return;
        st.insert(node);
        for(auto i : graph[node]){
            if(!done[i])dfs(i,mx);
            else if(st.count(i)) ret[node] = k;
            ret[node] = max(ret[node],ret[i]);
        }
        ret[node]++;
        st.erase(node);
    };
    function<bool(int)> check = [&](int mx){
        ans = false;
        done.clear();
        done.resize(n+1);
        ret.clear();
        ret.resize(n+1);
        for(int i=1;i<=n;i++){
            if(!done[i]){
                st.clear();
                dfs(i,mx);
            }
        }
        for(int i=1;i<=n;i++) if(ret[i]>=k)ans = true;
        return ans;
    };
    int l = 0, r = 1e9+5;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    if(r==1e9+5) cout<<-1<<endl;
    else cout<<r+1<<endl;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}