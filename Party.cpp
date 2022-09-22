#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
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
    int n,m; cin>>n>>m;
    int arr[n];
    int indeg[n+1]{};
    for(int i=0;i<n;i++)cin>>arr[i];
    
    int mn = 1e5;
    vector<pair<int,int>> v;
    for(int i=0;i<m;i++){
        int l,r; cin>>l>>r;
        v.push_back({l,r});
        indeg[l]++;
        indeg[r]++;
    }
    if(m%2==0){
        cout<<0<<endl;
        return;
    }
    int ans = 1e5;
    for(int i=1;i<=n;i++){
        if(indeg[i]&1){
            ans = min(ans,arr[i-1]);
        }
    }
    for(int i=0;i<m;i++){
        if(indeg[v[i].F]%2==0 && indeg[v[i].S]%2==0){
            ans = min(ans,arr[v[i].F-1]+arr[v[i].S-1]);
        }
    }
    cout<<ans<<endl;
}