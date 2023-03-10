#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
ll mod = 998244353;
vector<int> fact(2025),primes;
ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x%p;
    while(y>0){
        if(y&1)res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
bool MillerRabin(ll d, ll n){
    ll a = 2+rand()%(n-3);
    ll x = power(a,d,n);
    if(x==1 || x==n-1)return true;
    while(d!=n-1){
        x=(x*x)%n; d*=2;
        if(x==1)return false;
        if (x==n-1)return true;
    }
    return false;
}
bool isPrime(ll n, ll k){
    if(n<=1 || n==4)return false;
    if(n<=3)return true;
    ll d = n-1;
    while(d%2==0)d/=2;
    for(int i=0; i<k;i++){
        if(!MillerRabin(d,n))return false;
    }
    return true;
}
ll modularInverse(ll a){
    return power(a,mod-2,mod);
}
void code(){
    int n; cin>>n;
    vector<int> arr(2*n);
    map<int,int> m;
    fact[0] = 1;
    for(int i=1;i<2023;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    for(int i=0;i<2*n;i++){
        int k; cin>>k;
        if(!m.count(k) && isPrime(k,5))primes.push_back(k);
        m[k]++;
    }
    int k = primes.size();
    if(k<n){
        cout<<0<<endl;
        return;
    }
    int ans = fact[n];
    for(auto i : m){
        ans = ans*modularInverse(fact[i.S])%mod;
    }
    vector<vector<int>> f(k+1,vector<int>(n+1));
    for(int i=1;i<=k;i++){
        f[i][1] = f[i-1][1]+m[primes[i-1]];
        for(int j=2;j<=min(i,n);j++){
            f[i][j] = (f[i-1][j] + m[primes[i-1]]*f[i-1][j-1])%mod;
        }
    }
    cout<<f[k][n]*ans%mod<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}