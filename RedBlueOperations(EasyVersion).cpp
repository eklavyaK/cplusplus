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
    int arr[n]{}, sum = 0;
    for(int i=0;i<n;i++)cin>>arr[i], sum+=arr[i];
    sort(arr,arr+n);
    while(q--){
        int k; cin>>k;
        int mn = 2e9;
        if(k<=n){
            for(int i=0;i<n && k-i>=0;i++){
                mn = min(arr[i]+k-i,mn);
            }
            cout<<mn<<" ";
        }
        else if((k-n)&1){
            for(int i=0;i<n;i++){
                mn = min(arr[i]+k-i,mn);
            }
            mn = min(arr[n-1],mn);
            int curr = sum + (n-1)*k - (n-1)*(n-2)/2;
            cout<<min(mn,(curr-(k-n+2)/2)/n)<<" ";
        }
        else{
            for(int i=0;i<n;i++){
                mn = min(arr[i]+k-i,mn);
            }
            int curr = sum + n*k - n*(n-1)/2;
            cout<<min(mn,(curr-(k-n+1)/2)/n)<<" ";
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t  =  1; while(t--)code();
    return 0;
}