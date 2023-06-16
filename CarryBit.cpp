#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif

const int N = 1e6+5, mod = 1e9+7;
vector<ll> f(N,1);
ll exp(int a, int n){
    int res = 1;
    a%=mod;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod; n>>=1;
    }
    return res;
}
ll bc(ll n, ll r){
    return f[n]*exp(f[n-r],mod-2)%mod*exp(f[r],mod-2)%mod;
}

void code(int TC){
    int n,k, ans = 0; cin>>n>>k;
    for(int i=1;i<=n;i++) f[i] = f[i-1]*i%mod;
    int p3[n+1]{1};
    for(int i=1;i<=n;i++) p3[i] = p3[i-1]*3%mod;
    for(int r=1;r<=k;r++){
        int rem = n+1-k-r;
        if(rem<0) continue;
        int curr = bc(k-1,r-1)*p3[k-r]%mod;
        if(rem==0) ans = (ans + curr)%mod;
        else ans = (ans + curr*(bc(rem+r-1,r-1)*p3[rem]%mod+bc(rem+r-1,r)*p3[rem-1]%mod))%mod;
    }
    cout<<(k?ans:p3[n])<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; 
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}