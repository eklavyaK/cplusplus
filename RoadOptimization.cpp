#define PROGRAM int main(){rapid_iostream;int tc=1;while(tc-->0){codeforce();}return 0;}
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
    int n,l,k; cin>>n>>l>>k;
    int pos[n], time[n];
    for(int i=0;i<n;i++)cin>>pos[i];
    for(int i=0;i<n;i++)cin>>time[i];
    vector<vector<ll>> dp(n,vector<ll>(k+1,1e9));
    function<void(int,int)> compute = [&](int i, int rem){
        for(int j=i+1;j<min(n,i+rem+2);j++){
            if(dp[j][rem-(j-i-1)]==1e9) compute(j,rem-(j-i-1));
            dp[i][rem] = min(dp[i][rem],dp[j][rem-(j-i-1)]+(ll)(pos[j]-pos[i])*time[i]);
        }
        if(rem>=n-1-i)dp[i][rem] = min(dp[i][rem],(ll)(l-pos[i])*time[i]);
    };
    compute(0,k);
    cout<<*min_element(dp[0].begin(),dp[0].end())<<endl;
}