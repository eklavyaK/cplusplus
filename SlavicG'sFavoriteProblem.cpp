#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/



void codeforce(){
    int n,a,b; cin>>n>>a>>b;
    vector<vector<pair<int,int>>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    map<int,int> present;
    vector<int> atnode(n+1);
    vector<int> done(n+1);
    present[0] = 1; 
    bool ok = 0;
    int avoid = b;
    function<void(int)> dfs = [&](int node){
        done[node] = 1;
        if(avoid==-1 && present[atnode[node]] && node!=b) ok = 1;
        for(auto [u,w] : tree[node]){
            if(!done[u] && u!=avoid){
                atnode[u] = atnode[node]^w;
                if(avoid!=-1) present[atnode[u]] = 1;
                dfs(u);
            }
            else if(avoid==u && (atnode[node]^w)==0)ok = 1;
        }
    };
    dfs(a); avoid = -1;
    atnode.clear();atnode.resize(n+1);
    fill(done.begin(),done.end(),0);
    dfs(b); ok?Y():N();
}