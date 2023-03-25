#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k,d,w; cin>>n>>k>>d>>w;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        ans++;
        int c = k-1;
        int open = arr[i]+w;
        while(i+1<n && arr[i+1]<=open+d && c>0)i++,c--;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}