#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int par[200005][30];

void code(){
    int n,d; cin>>n>>d;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    par[1][0] = 1;
    function<void(int)> childrenise = [&](int node){
        for(auto i : tree[node]){
            if(i==par[node][0])continue;
            par[i][0] = node;
            childrenise(i);
        }
    };
    childrenise(1);
    
    for(int j=1;j<30;j++){
        for(int i=1;i<=n;i++){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    set<int> st,g,f;
    int m;  cin>>m;
    for(int j=0;j<m;j++){
        int k; cin>>k;
        st.insert(k);
        for(int i=0;i<30;i++){
            if((1<<i)&d)k=par[k][i];
        }
        g.insert(k);
    }
    cin>>m;
    for(int j=0;j<m;j++){
        int k; cin>>k;
        g.insert(k);
        for(int i=0;i<30;i++){
            if((1<<i)&d)k=par[k][i];
        }
        st.insert(k);
    }
    int ans = 0;
    bool a[n+1]{},b[n+1]{};
    while(!st.empty()){
        auto node = *st.begin();
        a[node] = 1; st.erase(node);
        if(!a[par[node][0]])st.insert(par[node][0]);
    }
    while(!g.empty()){
        auto node = *g.begin();
        b[node] = 1; g.erase(node);
        if(!b[par[node][0]])g.insert(par[node][0]);
    }
    for(int i=1;i<=n;i++){
        ans += 2*(a[i]+b[i]);
    }
    cout<<max(0ll,ans-4)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}