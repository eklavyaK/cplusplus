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
    sort(arr,arr+n);
    function<bool(int)> check = [&](int x){
        int cnt = 0, mx = 0;
        for(int i=0;i<n && cnt<3;i++){
            cnt++;
            mx = arr[i]+2*x;
            while(i+1<n && arr[i+1]<=mx)i++;
        }
        return mx>=arr[n-1];
    };
    int  l = 0, r = 1e9;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<r+1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}