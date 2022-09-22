#define PROGRAM int main(){rapid_iostream;int tc=1;while(tc-->0){codeforce();}return 0;}
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
    for(int i=0;i<n;i++)cin>>arr[i];
    int now[n]{}, revnow[n]{};
    for(int i=1;i<n;i++){
        now[i] = max(0,arr[i-1]-arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        revnow[i] = max(0,arr[i+1]-arr[i]);
    }
    long long sum[n],revsum[n];
    long long cnt = 0;
    for(int i=0;i<n;i++){
        cnt+=now[i];
        sum[i] = cnt;
    }
    cnt = 0;
    for(int i=n-1;i>=0;i--){
        cnt+=revnow[i];
        revsum[i] = cnt;
    }
    while(m--){
        int l, r; cin>>l>>r;
        l--;r--;
        if(l==r)cout<<0<<endl;
        else if(l<r)cout<<sum[r]-sum[l]<<endl;
        else if(r<l)cout<<revsum[r]-revsum[l]<<endl;
    }
}