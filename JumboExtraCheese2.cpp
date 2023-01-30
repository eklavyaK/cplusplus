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
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        v.push_back({max(a,b),min(a,b)});
    }
    sort(v.begin(),v.end());
    ll sum = 0;
    for(int i=0;i<n;i++){
        if(i==0){
            sum+=((ll)v[i].F+v[i].S)*2;
        }
        else{
            sum+=((ll)v[i].F+v[i].S-v[i-1].F)*2;
        }
    }
    cout<<sum<<endl;
}