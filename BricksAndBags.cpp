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

const int N = 2e5+5;
int n;
vector<ll> arr;
ll get_max(){
    ll mx = 0;
    for(int i=1;i<n-1;i++){
        mx = max(mx,2*arr[i+1]-arr[i]-arr[0]);
    }
    return mx;
}
ll get_min(){
    ll mx = 0;
    for(int i=0;i<n-2;i++){
        mx = max(mx,arr[i+1]+arr[n-1]-2*arr[i]);
    }
    return mx;
}
void codeforce(){
    cin>>n;
    arr.clear(); arr.resize(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll b = get_min();
    ll a = get_max();
    cout.precision(20);
    cout<<max(a,b)<<endl;
}