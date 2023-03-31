#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,x,y; cin>>n>>x>>y;
    string s,t; cin>>s>>t;
    int arr[n]{}, c = 0, f[n];
    for(int i=0;i<n;i++)if(s[i]!=t[i])arr[i] = 1,f[c++] = i;
    if(c&1){
        cout<<-1<<endl;
        return;
    }
    if(x>=y){
        if(c==2){
            for(int i=1;i<n;i++)if(arr[i]&&arr[i-1]){
                cout<<min(2*y,x)<<endl;
                return;
            }
        }
        cout<<(c>>1)*y<<endl;
        return;
    }
    if(c==0){
        cout<<0<<endl;
        return;
    }
    int dp[c];
    dp[0] = 0, dp[1] = min((f[1]-f[0])*x,y);
    for(int i=2;i<c;i++){
        if(i&1)dp[i]=min(dp[i-2]+(f[i]-f[i-1])*x,dp[i-1]+y);
       else dp[i]=min(dp[i-2]+(f[i]-f[i-1])*x,dp[i-1]);
    }
    cout<<dp[c-1]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}