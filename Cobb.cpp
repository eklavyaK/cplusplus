#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
    int n,k; cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll mx = LLONG_MIN;
    for(int i=max(0,n-750);i<n-1;i++){
        for(int j=i+1;j<n;j++){
            mx = max(mx,(ll)(i+1)*(j+1)-(ll)k*(arr[i]|arr[j]));
        }
    }
    cout<<mx<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}