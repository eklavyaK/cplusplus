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
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int x, ans = 0;; cin>>x;
    int done[n]{};
    for(int i=0;i<n;i++){
        if(arr[i]<x) continue;
        int l = i, sum = arr[i];
        done[i] = 1;
        while(i+1<n && arr[i+1]>=x){
            i++; sum+=arr[i]; done[i] = 1;
        }
        if(i==l){
            done[i] = 0; continue;
        }
        if(l-1>=0 && done[l-1]!=-1){
            if(arr[l-1]+arr[l]<x*2) done[l-1] = -1;
            else if(arr[l-1]+arr[l]>=x*2) done[l-1] = 1;
            if(done[l-1]==1) sum+=arr[l-1], --l;
        }
        if(i+1<n){
            if(arr[i+1]+arr[i]>=2*x && sum+arr[i+1]>=x*(i+2-l)) done[i+1] = 1;
            else done[i+1]=-1;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=x && !done[i]){
            if(i-1>=0 && i+1<n && done[i+1]==1 && done[i-1]==1){
                if(arr[i]+arr[i+1]+arr[i-1]>=x*3) done[i] = 1;
            }
            else{
                done[i] = 1;
                if(i-1>=0 && done[i-1]!=-1 && arr[i]+arr[i-1]>=x*2) done[i-1] = 1;
                else if(i-1>=0) done[i-1] = -1;
                if(i+1<n && done[i+1]!=-1 && arr[i]+arr[i-1]*(done[i-1]==1)+arr[i+1]>=x*(2+(done[i-1]==1))) done[i+1] = 1; 
                else if(i+1<n) done[i+1] = -1;
            }
        }
    }
    for(auto i : done) ans+=(i==1);
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}