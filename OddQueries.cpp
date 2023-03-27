#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,q; cin>>n>>q;
    int arr[n+1], sum[n+1]{};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i] = sum[i-1]+arr[i];
    }
    while(q--){
        int l,r,k; cin>>l>>r>>k;
        if((sum[n]-(sum[r]-sum[l-1])+(r-l+1)*k)&1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}