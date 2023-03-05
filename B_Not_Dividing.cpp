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
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1)arr[i]++;
    }
    for(int i=1;i<n;i++){
        if(arr[i]%arr[i-1]==0){
            arr[i]++;
        }
    }
    for(auto i : arr)cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}