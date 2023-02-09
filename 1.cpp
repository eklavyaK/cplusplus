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
    int arr[n], xr[n];
    map<int,vector<int>> m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0)xr[i] = arr[i];
        else xr[i] = xr[i-1]^arr[i];
        m[xr[i]].push_back(i);
    }
    while(q--){
        int l, r; cin>>l>>r;
        l--,r--;
        if((l==0 && xr[r]!=0) || (xr[l-1]!=xr[r])) cout<<-1<<endl;
        else if((l-r+1)&1) cout<<1<<endl;
        else if(!arr[l] || !arr[r]) cout<<1<<endl;
        else{
            
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}