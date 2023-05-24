#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int inf = 1e18;

void code(){
    int n,m,p; cin>>n>>m>>p;
    vector<vector<pair<int,int>>> graph(n);
    vector<pair<int,int>> s(n);
    for(int i=0;i<n;i++) cin>>s[i].F,s[i].S=i;
    s[n-1].F = inf;
    sort(s.begin(),s.end());
    for(int j=0;j<m;j++){
        int u,v,w; cin>>u>>v>>w;
        u--,v--;
        graph[u].push_back({v,w});
    }
    vector<vector<int>> dis(n,vector<int>(n,inf));
    function<void(int)> dijkstra = [&](int node){
        dis[node][node] = 0;
        set<pair<int,int>> st;
        st.insert({0,node});
        bool done[n]{};
        while(!st.empty()){
            auto [d,ver] = *st.begin();
            for(auto [v,w] : graph[ver]){
                if(dis[node][v]>d+w){
                    st.erase({dis[node][v],v});
                    dis[node][v] = d+w;
                    st.insert({dis[node][v],v});
                }
            }
            st.erase({d,ver});
        }
    };
    for(int i=0;i<n;i++) dijkstra(i);
    vector<pair<int,int>> dp(n,{inf,-inf});
    int idx = 0;
    for(int i=0;i<n;i++) if(!s[i].S) idx = i;
    dp[idx] = {0,p};
    for(int i=idx;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int l = s[i].S, r = s[j].S;
            if(dis[l][r]==inf) continue;
            int extra = dis[l][r]>=dp[i].S?(dis[l][r]-dp[i].S+s[i].F-1)/s[i].F:0;
            pair<int,int> now = {dp[i].F+extra,extra*s[i].F-dis[l][r]+dp[i].S};
            if(dp[j].F>now.F || dp[j].F==now.F && dp[j].S<now.S) dp[j] = now;
        }
    }
    cout<<(dp[n-1].F==inf?-1:dp[n-1].F)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}