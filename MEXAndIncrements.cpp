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
    vector<int> arr(n);
    set<pii> rem;
    ll cnt[n+1]{};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(cnt[arr[i]]){
            rem.insert({arr[i],i});
        }
        cnt[arr[i]]++;
    }
    bool t = 0;
    int in = 0;
    vector<ll> ans(n+1);
    sort(arr.begin(),arr.end());
    for(int i=0;i<=n;i++){
        if(t){
            ans[i] = -1;
            continue;
        }
        if(i<n && arr[i]>i){
            t = 1;
        }
        in = i;
    }
    ll sum = 0;
    ans[0] = cnt[0];
    for(int i=1;i<=in;i++){
        if(!cnt[i-1]){
            auto now = rem.lower_bound({i-1,0});
            now--;sum+=i-1-now->first;
            rem.erase(now);
        }
        ans[i] = cnt[i]+sum;
    }
    for(auto i : ans) cout<<i<<' ';
    cout<<endl;
}