#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
ll mod1 = 998244353;
ll power(ll n, ll k){
    long  long ans = 1;
    while(k>0){
        if(k&1)ans = (ans*n)%mod1;
        k>>=1; n = (n*n)%mod1;
    }
    return ans;
}
ll factorial(ll n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans=(ans*i)%mod1;
    }
    return ans;
}
ll modularInverse(ll a, ll p){
    return power(a,p-2);
}
ll binomialCoefficient(ll n, ll r){
    return (((factorial(n) * modularInverse(factorial(r),mod1))%mod1) * modularInverse(factorial(n-r),mod1))%mod1;
}

void code(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt2 = 0, cnt3=0;
    for(int i=0;i<n;i+=3){
        sort(arr+i,arr+i+3);
        if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2])cnt3++;
        else if(arr[i]==arr[i+1])cnt2++;
    }
    ll ans = binomialCoefficient(n/3,n/6);
    ans = ans*power(3,cnt3)%mod1;
    ans = ans*power(2,cnt2)%mod1;
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}