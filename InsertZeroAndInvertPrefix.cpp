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
    if(arr[n-1]){
        cout<<"NO"<<endl;
        return;
    }
    int ans[n]{}, cnt = 0;
    for(int i=n-1;i>=0;i--){
        while(i-1>=0 && arr[i-1]==arr[i]) i--;
        ans[cnt] = i, cnt++;
    }
    cout<<"YES"<<endl;
    reverse(ans,ans+n);
    for(auto i : ans) cout<<i<<' ';
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}