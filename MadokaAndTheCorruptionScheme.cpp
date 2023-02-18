#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
typedef long long ll;
typedef long double ld;
using namespace std;
ll mod1 = 1e9+7;
ll fact[100005];
ll power(ll n, ll k){
    long  long ans = 1;
    while(k>0){
        if(k&1)ans = (ans*n)%mod1;
        k>>=1; n = (n*n)%mod1;
    }
    return ans;
}
void factorial(ll n){
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)%mod1;
    }
}
ll modularInverse(ll a, ll p){
    return power(a,p-2);
}
ll binomialCoefficient(ll n, ll r){
    return (((fact[n] * modularInverse(fact[r],mod1))%mod1) * modularInverse(fact[n-r],mod1))%mod1;
}

void code(){
    int n,k; 
    cin>>n>>k;
    ll ans = 0;
    factorial(n);
    for(int i=0;i<=min(n,k);i++){
        ans = (ans + binomialCoefficient(n,i)) % mod1;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}