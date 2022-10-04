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
    ll n; cin>>n;
    ll arr[n], sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll divider = n*(n+1)/2;
    if(sum%divider!=0){
        N();return;
    }
    ll sigma = sum/divider;
    vector<ll> ans(n);
    for(int i=1;i<n;i++){
        if((sigma-arr[i]+arr[i-1])%n!=0){
            N();return;
        }
        ans[i] = (sigma-arr[i]+arr[i-1])/n;
        if(ans[i] <= 0 ){
            N();return;
        }
    }
    if((sigma-arr[0]+arr[n-1])%n!=0){
        N();return;
    }
    ans[0] = (sigma-arr[0]+arr[n-1])/n;
    if(ans[0] <= 0){
        N();return;
    }
    Y();
    for(auto i : ans) cout<<i<<' ';
    cout<<endl;
}