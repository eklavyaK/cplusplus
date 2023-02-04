#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int k; 
    cin>>k;
    bool arr[k];
    vector<int> onn, zrr;
    for(int i=0;i<k;i++){
        cin>>arr[i];
        if(arr[i])onn.push_back(i);
        else zrr.push_back(i);
    }
    int m = zrr.size(), n = onn.size();
    if(!n){cout<<0<<endl; return;}
    vector<vector<int>> dp(n,vector<int>(m,1e9));
    dp[0][0] = abs(zrr[0]-onn[0]);
    for(int i=1;i<m;i++){
        dp[0][i] = min(dp[0][i-1],abs(zrr[i]-onn[0]));
    }
    for(int i=1;i<n;i++){
        dp[i][i] = dp[i-1][i-1]+abs(zrr[i]-onn[i]);
        for(int j=i+1;j<m;j++){
            dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+abs(zrr[j]-onn[i]));
        }
    }
    cout<<*min_element(dp[n-1].begin()+n-1,dp[n-1].end())<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}