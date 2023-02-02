#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m,d;
    cin>>n>>m>>d;
    int arr[n], brr[m], pos[n+1];
    for(int i=0;i<n;i++)cin>>arr[i],pos[arr[i]] = i;
    for(int i=0;i<m;i++)cin>>brr[i];
    int ans = n;
    for(int i=0;i<m-1;i++){
        if(pos[brr[i]]>pos[brr[i+1]] ||pos[brr[i+1]]-pos[brr[i]]>d){
            cout<<0<<endl; return;
        }
        int k = pos[brr[i+1]]-pos[brr[i]];
        ans = min({ans,k,d-k+1+n*(d>=n-1)});
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}