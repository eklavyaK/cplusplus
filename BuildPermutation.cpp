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

ll closest_square(ll n){
    ll k = sqrt(n);
    while(true){
        ll now = k*k; k++;
        if(now>=n && now<=2*n)return now;
        else if(now>2*n)return -1;
    }
}

void codeforce(){
    int n; cin>>n;
    ll ans[n];
    for(int i=n-1;i>=0;i--){
        ll z = closest_square(i);
        if(z==-1){
            cout<<-1<<endl;
            return;
        }
        int start = z-i;
        for(int j=start;j<=i;j++){
            ans[j] = z-j;
        }
        i = start;
    }
    for(auto i : ans) cout<<i<<' ';
    cout<<endl;
}