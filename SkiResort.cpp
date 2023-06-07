#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k,q; cin>>n>>k>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>q) continue;
        int cnt = 1;
        while(i+1<n && arr[i+1]<=q)i++,cnt++;
        if(cnt>=k) ans+=(cnt-k+1)*(cnt-k+2)/2;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}