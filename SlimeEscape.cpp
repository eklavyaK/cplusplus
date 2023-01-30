#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
    int n,k; cin>>n>>k; int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int l = k, r = k; 
    ll now = arr[k], t = 0;
    while(l!=1 && r!=n){
        ll mx = now;
        while(l-1>=1 && arr[l-1]+now>=0){
            l--; now+=arr[l]; mx = max(mx,now);
        }
        t = mx-now; now = mx;int f=r;
        while(r+1<=n && arr[r+1]+now>=0){
            r++; now+=arr[r]; if(now>=mx)mx=now,f=r;
        }
        if(r==n || l==1)break;
        r = f;
        if(mx-t+arr[l-1]>=0){
            now = mx - t;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}