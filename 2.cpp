#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(int t){
    cout<<"Case #"<<t<<": ";
    int n,k; cin>>n>>k;
    int arr[n];
    map<int,int> m;
    for(int i=0;i<n;i++)cin>>arr[i],m[arr[i]] = i;
    sort(arr,arr+n);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int cnt = 0, curr = arr[i];
        for(int j=i-1;j>=0;j--){
            if(curr-arr[j]>=k){
                cnt++; 
                curr = arr[j];
            }
        }
        curr = arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]-curr>=k){
                cnt++;
                curr = arr[j];
            }
        }
        ans[m[arr[i]]] = cnt+1;
    }
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int i=1;i<=t;i++)code(t);
    return 0;
}