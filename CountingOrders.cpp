#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    vector<int> arr(n), brr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)cin>>brr[i];
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    int ans = 1, mod = 1e9+7;
    for(int i=n-1;i>=0;i--){
        int idx = upper_bound(arr.begin(),arr.end(),brr[i])-arr.begin();
        if(n-idx<=(n-i-1)){
            cout<<0<<endl;
            return;
        }
        ans = ans*(n-idx-(n-1-i))%mod;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}