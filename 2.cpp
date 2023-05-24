#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int inf = 1e15;

void code(){
    int n,m,p; cin>>n>>m>>p;
    vector<vector<pair<int,int>>> graph(n);
    vector<pair<int,int>> s(n);
    for(int i=0;i<n;i++) cin>>s[i].F,s[i].S=i;
    sort(s.begin(),s.end());
    for(int j=0;j<m;j++){
        int u,v,w; cin>>u>>v>>w;
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
            st.erase({d,ver});
            if(done[ver]) continue;
            done[ver] = 1;
            for(auto [v,w] : graph[ver]){
                if(dis[node][v]>d+w){
                    st.erase({dis[node][v],v});
                    dis[node][v] = d+w;
                    st.insert({dis[node][v],v});
                }
            }
        }
    };
    for(int i=0;i<n;i++) dijkstra(i);
    vector<pair<int,int>> dp(n,{inf,-inf});
    int idx = 0;
    for(int i=0;i<n;i++) if(!s[i].S) idx = i;
    dp[idx] = {0,p};
    for(int i=idx;i<n;i++){
        for(int j=i+1;j<m;j++){
            if(dis[i][j]==inf) continue;
            int extra = ceil((ld)(dis[i][j]-dp[i].S)/s[i].F);
            dp[j] = min(dp[j],{dp[i].F+extra,extra*s[i].F-dis[i][j]+dp[i].S});
        }
    }
    cout<<(dp[n-1].F==inf?-1:dp[n-1].F)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}