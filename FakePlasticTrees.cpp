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
    int n; cin>>n;
    int par[n+1]{};
    int indeg[n+1]{};
    ll now[n+1]{};
    for(int i=2;i<=n;i++){
        cin>>par[i];
        indeg[par[i]]++;
    }
    vector<ll> l(n+1),r(n+1);
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(now[node]<l[node]){
            cnt++; now[node] = r[node];
        }
        if(node==1)break;
        indeg[par[node]]--;
        now[par[node]] = min(now[par[node]]+now[node],r[par[node]]);
        if(!indeg[par[node]]){
            q.push(par[node]);
        }
    }
    cout<<cnt<<endl;
}