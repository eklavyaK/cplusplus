#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    int arr[n+1], cold[k+1], hot[k+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=k;i++)cin>>cold[i];
    for(int i=1;i<=k;i++)cin>>hot[i];
    vector<int> a;
    a.push_back(0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        a.push_back(arr[i]);
        while(i+1<=n && arr[i+1]==arr[i]) i++, ans+=hot[arr[i]];
    }
    n = a.size();
    int idx[k+1]{}, cold_dp[n+1]{}, sum[n+1]{};
    vector<int> hot_dp(n+1,1e18);

    // hot_dp[i] stores the minimum time when ith element was sent as hot and cold_dp[i] stores the minimum time when ith element was sent as cold
    for(int i=1;i<n;i++){
        if(idx[a[i]]) hot_dp[i] = min(hot_dp[idx[a[i]]+1], cold_dp[idx[a[i]]+1]) + sum[i-1]-sum[idx[a[i]]+1]+hot[a[i]];
        cold_dp[i] = min(hot_dp[i-1],cold_dp[i-1])+cold[a[i]];
        idx[a[i]] = i;
        sum[i] = sum[i-1]+cold[a[i]];
    }
    cout<<ans+min(hot_dp[n-1],cold_dp[n-1])<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}