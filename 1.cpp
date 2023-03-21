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
    int n; cin>>n;
    vector<vector<int>> f(n+5,vector<int>(2));
    for(int i=0;i<n;i++){
        int k; cin>>k;
        int z = 0;
        if(k)f[k-1][1]=(f[k-1][0]+2*f[k-1][1]+(k==1?1:0))%mod;;
        f[k+1][0]=(f[k][0]+2*f[k+1][0]+(!k?1:0))%mod;
        f[k+1][1]=2*f[k+1][1]%mod;
    }
    int ans = 0;
    for(int i=0;i<=n;i++){
        ans=(ans+f[i][0]+f[i][1])%mod;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}