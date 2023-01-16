#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
    int n,q; cin>>n>>q; int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int xr[n]; xr[0] = arr[0];
    ll sum[n]; sum[0] = arr[0];
    for(int i=1;i<n;i++){
        xr[i] = arr[i]^xr[i-1];
        sum[i] = sum[i-1]+arr[i];
    }
    int L,R; cin>>L>>R; L--; R--;
    while(true){
        int nowL = L, nowR = R;
        if(L==R)break;
        if(L==0){
            if(sum[R]-sum[L]-(xr[R]^xr[L])>=sum[R]-xr[R])L++;
            else if(sum[R-1]-xr[R-1]>=sum[R]-xr[R])R--;
        }
        else{
            if(sum[R]-sum[L]-(xr[R]^xr[L])>=sum[R]-sum[L-1]-(xr[R]^xr[L-1]))L++;
            else if(sum[R-1]-sum[L-1]-(xr[R-1]^xr[L-1])>=sum[R]-sum[L-1]-(xr[R]^xr[L-1]))R--;
        }
        if(L==nowL && R==nowR){
            break;
        }
    }
    ll s = 0, x = 0;
    if(L==0)s = sum[R]; else s = sum[R]-sum[L-1];
    if(L==0)s = xr[R]; else s = xr[R]-xr[L-1];
    map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.count(sum[i]-s)){
            if(i-m[sum[i]]<R-L+1 && xr[i]^xr[m[sum[i]]]<=xr[L-1]^xr[R])R = i, L = m[sum[i]]+1;
        }
        else if(sum[i]==s){
            if(i-m[sum[i]]<R-L+1 && xr[i]^xr[m[sum[i]]]<=xr[L-1]^xr[R])R = i, L = m[sum[i]]+1;
        }
        m[sum[i]] = i;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}