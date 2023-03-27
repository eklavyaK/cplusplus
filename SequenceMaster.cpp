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
    vector<int> arr(2*n);
    for(int i=0;i<2*n;i++)cin>>arr[i];
    if(n==1){
        cout<<abs(arr[0]-arr[1])<<endl;
        return;
    }
    int sum = 0, s = 0, f = 0;
    for(int i=0;i<2*n;i++){
        sum+=abs(arr[i]);
        s+=abs(arr[i]-2);
        f+=abs(arr[i]+1);
    }
    int ans = LLONG_MAX;
    for(int i=0;i<2*n;i++){
        ans = min(ans,f-abs(arr[i]+1)+abs(arr[i]-n));
    }
    if(n==2)cout<<min({ans,s,sum})<<endl;
    else if(n%2==0)cout<<min(ans,sum)<<endl;
    else cout<<sum<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}