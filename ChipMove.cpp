#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int mod = 998244353;

void code(){
    int n,k; cin>>n>>k;
    vector<int> dp(n+1);
    vector<vector<int>> f(2,vector<int>(n+1));
    for(int i=1;i*k<=n;i++){
        dp[i*k] = f[0][i*k] = 1;
    }
    function<int(int,int,int)> update = [&](int j, int k, int l){
        for(int i=j;i<=n;i++){
            f[1-l][i] = 0;
        }
        for(int i=j+k+1;i<=n;i++){
            f[1-l][i] = (f[l][i-k-1]+f[1-l][i-k-1])%mod;
            dp[i] = (dp[i]+f[1-l][i])%mod;
        }
        return j+k+1;
    };
    int id = k, l = 0;
    for(int i=k;i<=n;i++){
        id = update(id,i,l);
        if(id>n)break;
        else l = 1-l;
    }
    for(int i=1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t   =  1; while(t--)code();
    return 0;
}