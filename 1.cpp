#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif


const int N = 105, M = 1e9+7;
int dp[N][20005];
int add(int A){
    if(A>M) A-=M;
    return A;
}
void code(int TC){
    int n,x; cin>>n>>x;
    int a[n], ans = 0;
    for(int i=0;i<n;i++) cin>>a[i], a[i]-=x;
    sort(a,a+n);
    for(int i=1;i<n;i++){
        for(int j=i;j<n-1;j++){
            for(int k=0;k<=20000;k++){
                dp[j][k] = add(dp[j][k] + dp[j-1][k]);
                if(k+a[j]>=0 && k+a[j]<=20000) dp[j][k+a[j]] = add(dp[j][k+a[j]]+dp[j-1][k]);
            }
            dp[j][a[j]+10000] = add(dp[j][a[j]+10000] + 1);
            ans = add(ans + dp[j][10000]);
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<=20000;k++) dp[j][k] = 0;
        }
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}