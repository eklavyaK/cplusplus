#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


const int inf = 1e18;

void code(){
    int n,k; cin>>n>>k;
    vector<int> arr(n+1),cold(k+1),hot(k+1);
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=k;i++)cin>>cold[i];
    for(int i=1;i<=k;i++)cin>>hot[i];
    vector<vector<int>> f(2,vector<int>(k+1,inf));
    for(int i=0;i<=k;i++) f[0][i] = f[1][i] = 0;
    for(int i=n;i>=1;i--){
        vector<vector<int>> dp(2,vector<int>(k+1));
        for(int j=0;j<=k;j++){
            for(int l=0;l<2;l++){
                if(arr[i]==arr[i-1]) dp[l][j] = hot[arr[i]] + f[l][j];
                else if(arr[i]==j) dp[l][j] = hot[j] + f[1-l][arr[i-1]];
                else dp[l][j] = cold[arr[i]] + min(f[l][j],f[1-l][arr[i-1]]);
            }
        }
        f = dp;
    }
    cout<<min(f[0][0],f[1][0])<<endl;
} 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}