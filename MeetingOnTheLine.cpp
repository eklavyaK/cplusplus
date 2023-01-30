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
    cout.precision(20);
    int n; cin>>n;
    vector<pair<int,int>> pos(n);
    for(int i=0;i<n;i++){
        cin>>pos[i].F;
    }
    for(int i=0;i<n;i++){
        cin>>pos[i].S;
    }
    sort(pos.begin(),pos.end());
    if(n==1){
        cout<<pos[0].F<<endl;
        return;
    }
    int u = -1e9, v = 1e9;
    vector<int> forward(n),backward(n),mx(n);
    for(int i=0;i<n;i++){
        forward[i] = pos[i].F-pos[i].S;
        backward[i] = pos[i].F+pos[i].S;
        u = max(u,backward[i]);
        v = min(v,forward[i]);
    }
    cout<<((ld)u+v)/2<<endl;
    // int m = 0;
    // for(int i=n-1;i>=0;i--){
    //     m = max(m,backward[i]);
    //     mx[i] = m;
    // }
    // int mn = 1e9;
    // ld ans = 1e9;
    // ld x = 0;
    // for(int i=0;i<n-1;i++){
    //     mn = min(mn,forward[i]);
    //     long double k = ((ld)mx[i+1] + mn)/2;
    //     if(abs(mn-k)<ans){
    //         ans = abs(mn-k);
    //         x = k;
    //     }
    // }
    // cout<<x<<endl;
}