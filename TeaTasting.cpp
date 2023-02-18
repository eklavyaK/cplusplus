#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    ll n; cin>>n;
    ll a[n+1]{},b[n+1]{};
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)cin>>b[i];
    ll sum[n+2]{};
    for(ll i=1;i<=n;i++){
        sum[i] = sum[i-1]+b[i];
    }
    ll ans[n+2]{}, arr[n+1]{};
    int cnt = 0;
    for(ll i=1;i<=n;i++){
        ll l = i, r = n;
        while(l<=r){
            ll mid = (l+r)>>1;
            if(sum[i-1]+a[i]-sum[mid]>=0)l = mid+1;
            else r = mid-1;
        }
        ll k = l;
        ans[k]+=a[i]+sum[i-1]-sum[k-1];
        arr[k]++;
        cnt-=(arr[i]-1);
        ans[i] += b[i]*cnt;
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}