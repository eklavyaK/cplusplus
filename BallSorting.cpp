#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 5e2+5;
int dp[2][N][N], arr[N];

void code(){
    int n; cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=2;i<=n;i++)
        for(int j=0;j<=n;j++) 
            for(int k=0;k<2;k++) dp[k][i][j] = i;
    for(int i=1;i<=n;i++){
        if(arr[i]>arr[i-1])
            for(int k=0;k<2;k++) dp[k][i][0] = 0;
        else break;
    }
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            for(int k=1;k<=n;k++){
                if(arr[j]<arr[i]) dp[1][i][k] = min(dp[1][i][k],dp[1][j][k-1*(j!=i-1)]+(i-j-1));
                dp[0][i][k] = min(dp[0][i][k],dp[1][j][k-1]+(i-j));
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<min(dp[1][n][i],dp[0][n][i])<<' ';
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}