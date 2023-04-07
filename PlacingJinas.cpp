#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
const int mod = 1e9+7;
const int N = 4e5+5;
int fact[N];
int exp(int a, int k){
    int res = 1;
    a%=mod;
    while(k>0){
        if(k&1) res = (res*a)%mod;
        a = (a*a)%mod; k>>=1;
    }
    return res;
}
void factorial(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}
int bc(int n, int r){
    return fact[n]*exp(fact[n-r]*fact[r] ,mod-2)%mod;
}
void code(){
    factorial();
    int n; cin>>n;
    int ans = 0;
    for(int i=0;i<=n;i++){
        int k; cin>>k;
        if(!k)continue;
        ans = (ans+bc(i+k,i+1))%mod;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t  =  1; while(t--)code();
    return 0;
}