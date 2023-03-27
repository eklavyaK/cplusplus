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
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)cin>>brr[i];
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[n-1]){
            swap(arr[i],brr[i]);
            if(arr[i]>arr[n-1]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(brr[i]>brr[n-1]){
            swap(arr[i],brr[i]);
            if(brr[i]>brr[n-1]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[n-1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}