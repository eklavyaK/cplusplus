#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    int arr[n], pos[n], st[n], en[n];
    for(int i=0;i<n;i++)cin>>arr[i],pos[arr[i]] = i;
    int l = n, r = -1;
    for(int i=0;i<n;i++){
        l = min(l,pos[i]);
        r = max(r,pos[i]);
        st[i] = l, en[i] = r;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int c = (i-1)>>1;
        if(i<=en[c]-st[c])continue;
        ans+=(min(n-max(en[c],i-1),st[c]-max(0ll,en[c]-i+1)+1));
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}