#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int mod = 998244353, f[300005];
ll exp(ll n, ll k){
    long  long ans = 1;
    n%=mod;
    while(k>0){
        if(k&1)ans = (ans*n)%mod;
        k>>=1; n = (n*n)%mod;
    }
    return ans;
}
void factorial(){
    f[0] = 1;
    for(int i=1;i<=3e5;i++){
        f[i]=(f[i-1]*i)%mod;
    }
}
ll modularInverse(ll a, ll p){
    return exp(a,p-2);
}
ll bc(ll n, ll r){
    return (((f[n]*modularInverse(f[r],mod))%mod)*modularInverse(f[n-r],mod))%mod;
}
void code(){
    int n,m; cin>>n>>m;
    int arr[n], sum = 0, curr = 0;
    for(int i=0;i<n;i++)cin>>arr[i],sum+=arr[i];
    sum>>=1;
    set<int> st;
    int M = 0;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(st.count(curr-sum))M++;
        st.insert(curr);
    }
    factorial();
    int dp[M+2]{}, ch = 0;
    curr = 0;
    for(int i=M;i>=0;i--){
        if(m<i) continue;
        else if(m==i && n-(i<<1)>0) continue;
        if(ch){
            int k = ((bc(M,i+1)*bc(m,i+1))%mod*f[i+1])%mod;
            cout<<k<<endl;
            dp[i] = (((m-i)*(m-i-1)*(i+1))%mod*2*k)%mod;
        }
        else dp[i] = (((bc(M,i)*bc(m,i))%mod*f[i])%mod*exp(m-i,n-(i<<1)))%mod, ch = 1;
    }
    int ans = 0;
    for(int i=0;i<=M;i++)ans+=dp[i];
    cout<<ans%mod<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t   =  1; while(t--)code();
    return 0;
}