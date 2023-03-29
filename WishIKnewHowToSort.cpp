#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
const int mod = 998244353;
ll exp(ll n, ll k){
    long  long ans = 1;
    n%=mod;
    while(k>0){
        if(k&1)ans = (ans*n)%mod;
        k>>=1; n = (n*n)%mod;
    }
    return ans;
}
void code(){
    int n; cin>>n;
    int arr[n], cnt = 0;
    for(int i=0;i<n;i++)cin>>arr[i],cnt+=arr[i];
    int k = n-cnt; cnt = 0;
    for(int i=0;i<k;cnt+=!arr[i],i++);
    int f[k+1]{}, c = (n*(n-1)/2)%mod;
    for(int i=k-1;i>=cnt;i--){
        f[i] = (c*exp((k-i)*(k-i),mod-2)+f[i+1])%mod;
    }
    cout<<f[cnt]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}