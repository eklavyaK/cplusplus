#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k,x; cin>>n>>k>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i],arr[i]-=x;
    int c = 0, sum[n+1]{};
    for(int i=0;i<n;i++){
        c+=arr[i];
        sum[i+1] = c;
    }
    for(int i=0;i<n;i++){
        
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}