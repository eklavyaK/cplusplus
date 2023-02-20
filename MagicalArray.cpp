#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m; cin>>n>>m;
    int ans = 0, cnt = 0;
    int mx = 0, mn = 1e18+5;
    for(int i=1;i<=n;i++){
        int curr = 0;
        for(int j=1;j<=m;j++){
            int k; cin>>k;
            curr+=k*j;
        }
        mn = min(curr,mn);
        if(curr>=mx)mx = curr, ans = i;
    }
    cout<<ans<<' '<<mx-mn<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}