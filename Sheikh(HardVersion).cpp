#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif





void code(int TC){
    int n,q; cin>>n>>q;
    int arr[n+2]{};
    for(int i=1;i<=n;i++)cin>>arr[i];
    int xrr[n+2]{},xrb[n+2]{}, sum[n+2], lf[n+2]{},lb[n+2]{};
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+arr[i];
        xrr[i] = xrr[i-1]^arr[i];
    }
    for(int i=1;i<=n;i++){
        int l = i;
        while(i+1<=n && arr[i+1]==0) i++;
        for(int j=l;j<=i;j++) lf[j] = i+1;
    }
    for(int i=n;i>=1;i--){
        int r = i;
        while(i-1>=1 && arr[i-1]==0) i--;
        for(int j=r;j>=i;j--) lb[j] = i-1;
    }
    while(q--){
        int l,r; cin>>l>>r;
        int mx = sum[r]-sum[l-1];
        int xr = xrr[r]^xrr[l-1];
        int ansl = l, ansr = r;
        if(ansl==ansr){
            cout<<ansr<<' '<<ansr<<endl;
            continue;
        }
        int new_xr = xr;
        for(int i=l;i<=r;i=lf[i]){
            int curr = r;
            int y = arr[r];
            int new_yr = new_xr;
            while(curr>i && (arr[curr]&new_yr)==arr[curr]){
                new_yr -= arr[curr], curr = lb[curr];
            }
            if(curr>=i && ansl-ansr<i-curr) ansl = i, ansr = curr;
            else if(curr<i) ansl = i, ansr = i;
            if((new_xr&arr[i])!=arr[i]) break;
            new_xr -= arr[i];
        }
        cout<<ansl<<" "<<ansr<<endl;
        //debug("");
    }
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}