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
    map<int,int> cnt, a, mn;
    int mx = 0, ans = 0, l = 0, r = 0;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        cnt[k]++;
        if(cnt[k]==1){
            mn[k] = 2 - i;
            a[k] = i;
            if(ans<1){
                ans = 1;
                mx = k;
                l = i+1; r = i+1;
            }
            continue;
        }
        if(ans<2*cnt[k]-i-mn[k]+1){
            ans = 2*cnt[k]-i-mn[k]+1;
            l = a[k]+1; r = i+1;
            mx = k;
        }
        if(2*cnt[k]-i<mn[k]){
            mn[k] = 2*cnt[k]-i;
            a[k] = i;
        }
    }
    cout<<mx<<' '<<l<<' '<<r<<endl;
}