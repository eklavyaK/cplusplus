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
    vector<pair<int,int>> arr(n);
    set<int> in[n+1];
    bool k = 0;
    for(int i=0;i<n;i++){
        int u,v; cin>>u>>v;
        in[u].insert(i);
        in[v].insert(i);
        arr[i]={u,v};
        if(u==v || in[u].size()>2 || in[v].size()>2){
            k = 1;
        }
    }
    if(k){
        N();return;
    }
    int done[n]{};
    set<int> st[2];
    function<void(int,int)> dfs = [&](int c, bool set){
        done[c] = 1;
        int x = arr[c].F;
        int y = arr[c].S;
        if(!st[set].count(x) && !st[set].count(y)){
            st[set].insert(x);st[set].insert(y);
        }
        else k = 1;
        in[x].erase(c);
        in[y].erase(c);
        if(in[x].size()){
            int now = *in[x].begin();
            if(!done[now])dfs(now,!set);
        }
        if(in[y].size()){
            int now = *in[y].begin();
            if(!done[now])dfs(now,!set);
        }
    };
    for(int i=0;i<n;i++){
        if(!done[i]) dfs(i,0);
    }
    k?N():Y();
}