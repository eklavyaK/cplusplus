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
    vector<vector<pair<int,pair<int,int>>>> tree(n+1);
    vector<pair<int,int>> store(n+1);
    for(int i=2;i<=n;i++){
        int p,a,b; cin>>p>>a>>b;
        tree[i].push_back({p,{a,b}});
        tree[p].push_back({i,{a,b}});
    }
    vector<ll> track, ans(n+1);
    bool done[n+1]{}; done[1] = 1;
    function<void(int,ll)> dfs = [&](int node, ll sum){
        done[node] = 1;
        int index = lower_bound(track.begin(),track.end(),sum)-track.begin();
        if(index == track.size()) ans[node] = track.size()-1;
        else if(track[index] == sum) ans[node] = index;
        else ans[node] = index-1;
        for(auto [u,c] : tree[node]){
            if(!done[u]){
                track.push_back(track.back()+c.S); dfs(u,sum+c.F);
            }
        }
        track.pop_back();
    };
    track.push_back(0);
    for(auto [u,c] : tree[1]) if(!done[u]){
        track.push_back(c.S); dfs(u,c.F);
    }
    for(int i=2;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
}