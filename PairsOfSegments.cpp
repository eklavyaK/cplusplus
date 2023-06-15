#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

bool func(pair<int,int> a, pair<int,int> b){
    if(a.S==b.S){
        return a.F<b.F;
    }
    else return a.S<b.S;
}

void code(){
    int n; cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].F>>v[i].S;
    }
    sort(v.begin(),v.end(),func);
    int dp[n]{};
    for(int i=1;i<n;i++){
        dp[i] = dp[i-1];
        int mx = -1;
        for(int j=0;j<i;j++){
            if(v[i].F<=v[j].S){
                mx = max(mx,v[j].F);
            }
        }
        if(mx==-1) continue;
        mx = min(v[i].F,mx);
        int idx = -1;
        for(int j=0;j<i;j++){
            if(v[j].S<mx) idx = j;
            else break;
        }
        if(idx==-1) dp[i] = max(dp[i],2ll);
        else dp[i] = max(dp[i],dp[idx]+2);
    }
    cout<<n-dp[n-1]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}