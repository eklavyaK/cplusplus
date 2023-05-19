#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n; ++n;
    vector<int> arr(n);
    for(int i=1;i<n;i++)cin>>arr[i];
    reverse(arr.begin()+1,arr.end());
    int k = (1+sqrt(1+(ld)8*n))*0.5+3;
    int dp[n][k]; ll sum[n]{};
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++) sum[i] = sum[i-1]+arr[i];
    for(int i=0;i<n;i++) dp[i][0] = 1e9+5;
    for(int i=1;i<n;i++){
        for(int j=1;j<k;j++){
            if(i-j>=0 && dp[i-j][j-1]>sum[i]-sum[i-j]) dp[i][j] = (int)sum[i]-sum[i-j];
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<k;i++) ans+=(dp[n-1][i]>0);
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}