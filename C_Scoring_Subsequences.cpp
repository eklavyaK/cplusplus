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
    vector<int> arr(n);
    int cnt = 0;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        int l = 0, r = i;
        while(l<=r){
            int mid = (l+r)>>1;
            if((i+1-mid)<=arr[mid]) r = mid-1;
            else l = mid+1;
        }
        cout<<i-r<<' ';
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}