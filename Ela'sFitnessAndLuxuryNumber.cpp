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

int t = 0;

void codeforce(){
    cout.precision(20);
    ll ans = 0;
    ll x = 0, y = 0;
    ll a,b; cin>>a>>b;
    ld sa = sqrt((ld)a), sb = sqrt((ld)b);
    if(sa==(ll)sa){
        x = sa;
    }
    else x = (ll)sa+1;
    y = sb;
    sa = x*x;
    sb = y*y;
    ans = (y-x)*3+1;
    x--;sa--;
    if(sa>=a)ans++;
    if(sa-x>=a && x!=0)ans++;
    if(sa-2*x>=a && x!=0)ans++;
    if(sa-3*x>=a && x!=0)ans++;
    if(sb+y<=b && y!=0)ans++;
    if(sb+2*y<=b && y!=0)ans++;
    if(sb+2*y+1<=b && y!=0)ans++;
    cout<<ans<<endl<<flush;
}