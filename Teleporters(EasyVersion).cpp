#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

void code(){
    int n,c; cin>>n>>c;
    int arr[n+1]{};
    for(int i=1;i<=n;i++)cin>>arr[i], arr[i]+=i;
    sort(arr,arr+n+1);
    int ans = 0, cnt = 0;
    for(int i=1;i<=n;i++){
        if(arr[i]>c)break;
        else c-=arr[i],cnt++;
    }
    cout<<cnt<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;while(t--)code();
    return 0;
}