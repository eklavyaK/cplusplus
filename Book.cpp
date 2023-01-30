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
    int indeg[n+1]{};
    queue<int> q; int ans = 0;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n;i++){
        int k; cin>>k;
        indeg[i+1] = k;
        while(k--){
            int u; cin>>u;
            tree[u].push_back(i+1);
        }
        if(!indeg[i+1])q.push(i+1);
    }
    vector<int> dist(n+1,1);
    while(!q.empty()){
        int node = q.front(); q.pop();
        ans = max(ans,dist[node]);
        for(auto i : tree[node]){
            indeg[i]--;
            dist[i] = max(dist[i],dist[node]+1*(i<node));
            if(!indeg[i])q.push(i);
        }
    }
    if(count(indeg,indeg+n+1,0)!=n+1)cout<<-1<<endl;
    else cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}