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
    int ans = 0, k = 0, r = n+1;
    for(int i=0;i<n;i++){
        if(!arr[i]){
            r = i;
            break;
        }
        k+=arr[i];
        if(!k)ans++;
    }
    for(int i=r;i<n;i++){
        map<int,int> m;
        m[arr[i]]++;
        while(i+1<n && arr[i+1]!=0){
            i++;
            arr[i] = arr[i]+arr[i-1];
            m[arr[i]]++;
        }
        int mx = 0;
        for(auto j : m){
            mx = max(mx,j.S);
        }
        ans += mx;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}