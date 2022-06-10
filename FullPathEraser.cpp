#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define N() cout<<"NO"<<endl
#define MAIN void codeforce();
#define print(n) cout<<n<<' '
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
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/
const int inf = 300005;

void codeforce(){
    int n; cin>>n;
    int beauty[n+1];
    int check[n+1]{};
    int count[n+1]{};
    int parent[n+1]{};
    for(int i=1;i<=n;i++){
        cin>>beauty[i];
    }
    ll ans = 0;
    vector<vector<int>> edge(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        count[u]++;count[v]++;
    }
    parent[1]=1;
    queue<int> s;
    s.push(1);
    while(!s.empty()){
        int k = s.front();s.pop();
        for(auto i : edge[k]){
            if(parent[k]!=i){
                parent[i]=k;
                s.push(i);
            }
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(count[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int k = q.front(); q.pop();
        if(parent[k]!=k){
            beauty[parent[k]]=gcd(beauty[parent[k]],beauty[k]);
            count[parent[k]]--;if(count[parent[k]]==1)q.push(parent[k]);
        }
    }
    queue<pair<int,ll>> bfs;
    bfs.push({1,0});
    while(!bfs.empty()){
        auto [node,sum] = bfs.front();bfs.pop();
        for(auto i : edge[node]){
            if(parent[node]!=i)sum+=beauty[i];
        }
        for(auto i : edge[node]){
            if(parent[node]!=i)
            bfs.push({i,sum-beauty[i]});
        }
        ans = max(sum,ans);
    }
    cout<<ans<<endl;
}