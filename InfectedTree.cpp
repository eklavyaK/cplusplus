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
    int value[n+1];
    int check[n+1]{};
    int count[n+1]{};
    int parent[n+1]{};
    for(int i=1;i<=n;i++){
        value[i]=1;
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
            value[parent[k]]+=value[k];
            count[parent[k]]--;if(count[parent[k]]==1)q.push(parent[k]);
        }
    }
    queue<pair<int,ll>> bfs;
    bfs.push({1,0});
    if(edge[1].size()==1){
        cout<<n-2<<endl;
        return;
    }
    while(!bfs.empty()){
        auto [node,sum] = bfs.front();bfs.pop();
        ans = max(ans,sum);
        if(edge[node].size()==1)continue;
        if(edge[node].size()==2 && node!=1){
            ans = max(ans, value[node]-2+sum);
            continue;
        }
        array<array<int,2>,2> x; int cnt = 0;
        for(auto i : edge[node]){
            if(parent[node]!=i){
                x[cnt][0]=value[i];
                x[cnt][1]=i;
                cnt++;
            }
        }
        bfs.push({x[0][1],x[1][0]+sum-1});
        bfs.push({x[1][1],x[0][0]+sum-1});
    }
    cout<<ans<<endl;
}