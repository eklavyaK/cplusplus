#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


void code(){
    int n,m,r; cin>>n>>m>>r;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(r+1,1)));
    int k = 1e9;
    for(int i=0;i<r;i++){
        int t,d,coor; cin>>t>>d>>coor;
        if(coor==0) k = min(t,k);
        if(d==1) {
            for(int j=0;j<=m;j++) 
                if(t>=j+coor && t<j+coor+r+1) dp[coor][j][t-j-coor] = 0;
        }
        if(d==2) {
            for(int j=0;j<=n;j++) 
                if(t>=j+coor && t<j+coor+r+1) dp[j][coor][t-j-coor] = 0;
        }
    }
    for(int i=k;i<r+1;i++) dp[0][0][i] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0&&j==0) continue;
            for(int k=0;k<r+1;k++){
                dp[i][j][k] = ((i>0 && dp[i-1][j][k])|(j>0 && dp[i][j-1][k])|(k>0 && dp[i][j][k-1]))&dp[i][j][k];
            }
        }
    }
    int ans = -1;
    for(int i=0;i<r+1;i++){
        if(dp[n][m][i]){
            ans = n+m+i; break;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}