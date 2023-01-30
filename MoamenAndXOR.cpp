#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int mod = 1e9+7;
ll exp(ll a, ll n){
    ll res = 1;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return res;
}
ll modularInverse(ll a){
    return exp(a,mod-2);
}
void codeforce(){
    ll n, k; cin>>n>>k;
    if(n&1){
        cout<<exp(exp(2,n-1)+1,k)<<endl;
    }
    else{
        ll den = modularInverse((exp(2,n-1)+1)%mod);
        ll res = (exp((exp(2,n-1)-1+mod)%mod,k)+(((exp(exp(2,n),k)-exp((exp(2,n-1)-1+mod)%mod,k)+mod)%mod)*den)%mod)%mod;
        cout<<res<<endl;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        codeforce();
    }
    return 0;
}