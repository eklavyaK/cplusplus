#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k,x; 
    cin>>n>>k>>x;
    if(x<0) k=n-k, x*=-1;
    int a, brr[n+1], crr[n+1]{}, sum[n+1]{}, c = 0;
    for(int i=1;i<=n;i++)cin>>a,brr[i] = a-x, c+=brr[i], sum[i] = c, crr[i] = sum[i]+2*i*x;
    int ans = 0, mx = LLONG_MIN;
    set<pair<int,int>> st;
    for(int i=n;i>=1;i--){
        st.insert({crr[i],i});
        if(i+k<=n){
            mx = max(mx,sum[i+k]);
            st.erase({crr[i+k],i+k});
            int curr = crr[i+k-1]-crr[i-1];
            ans = max(ans,curr+mx-sum[i+k-1]);
        }
        if(!st.empty()){
            ans = max(ans,st.rbegin()->F-crr[i]+brr[i]+2*x);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}