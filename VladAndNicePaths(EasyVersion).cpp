#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 105;
int f[N][N], mod = 1e9+7;

void code(){
    int n,k; cin>>n>>k;
    int dp[n+1][n+1], arr[n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(k==1){
        cout<<1<<endl;
        return;
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        int c = 0;
        for(int j=i;j>0;j--){
            if(arr[j]!=arr[i]) continue;
            c++;
            if(c<k) continue;
            for(int l=1;l<=n;l++){
                dp[i][l] = (dp[i][l]+dp[j-1][l-1]*f[c-2][k-2])%mod;
            }
        }
        for(int l=0;l<=n;l++) dp[i][l] = (dp[i][l]+dp[i-1][l])%mod;
    }
    for(int i=n;i>=0;i--){
        if(dp[n][i]!=0){
            cout<<dp[n][i]<<endl;
            return;
        }
    }
}

signed main(){
    for(int i=0;i<N;i++)f[i][0] = 1;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            f[i][j] = (f[i-1][j]+f[i-1][j-1])%mod;
        }
    }
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}