#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> hrr(n,vector<int>(m-1));
    vector<vector<int>> vrr(n-1,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++)cin>>hrr[i][j];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++)cin>>vrr[i][j];
    }
    if(k&1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<-1<<' ';
            cout<<endl;
        }
        return;
    }
    int dp[n][m][k+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j][0] = 0;
            for(int t=1;t<=k;t++)dp[i][j][t]=1e9;
        }
    }
    for(int r=2;r<=k;r+=2){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0)for(int z=r-2;z>=0;z-=2)dp[i][j][r] = min(dp[i][j][r],dp[i-1][j][z]+(r-z)*vrr[i-1][j]);
                if(j-1>=0)for(int z=r-2;z>=0;z-=2)dp[i][j][r] = min(dp[i][j][r],dp[i][j-1][z]+(r-z)*hrr[i][j-1]);
                if(i+1<n)for(int z=r-2;z>=0;z-=2)dp[i][j][r] = min(dp[i][j][r],dp[i+1][j][z]+(r-z)*vrr[i][j]);
                if(j+1<m)for(int z=r-2;z>=0;z-=2)dp[i][j][r] = min(dp[i][j][r],dp[i][j+1][z]+(r-z)*hrr[i][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j][k]<<' ';
        }
        cout<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}