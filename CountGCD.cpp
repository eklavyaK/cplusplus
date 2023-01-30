#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;
ll mod = 998244353;
ll count(ll a, ll b){
    ll ret = 0;
    vector<ll> v;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            v.push_back(i);
            while(a%i==0)a/=i;
        }
    }
    if(a!=1) v.push_back(a);
    for(int i=1;i<(1<<v.size());i++){
        ll num = 1;
        for(int j=0;j<v.size();j++){
            if((1<<j)&i)num*=v[j];
        }
        ret+=(__builtin_popcount(i)&1?-1:1)*(b/num);
    }
    return b+ret;
}
void code(){
    ll ans=1; 
    int n,m; cin>>n>>m; int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        if(arr[i-1]%arr[i]){
            cout<<0<<endl;
            return;
        }
        ans = (ans*count(arr[i-1]/arr[i],m/arr[i]))%mod;
    }
    cout<<ans<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}