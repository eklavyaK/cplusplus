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
    int arr[n],f[n]{1};
    for(int i=0;i<n;i++)cin>>arr[i];
    int x; cin>>x;
    if(n>1 && arr[0]+arr[1]>=x*2) f[1] = 1;
    for(int i=2;i<n;i++){
        if(f[i-1] && f[i-2]){
            if(arr[i-1]+arr[i-2]+arr[i]>=x*3) f[i] = 1;
            if(arr[i-1]+arr[i]<x*2) f[i] = 0;
        }
        else if(f[i-1]){
            if(arr[i-1]+arr[i]>=x*2) f[i] = 1;
        }
        else f[i] = 1;
    }
    int ans = 0;
    for(auto i : f) ans+=i;
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}