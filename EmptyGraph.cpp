#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    vector<pair<int,int>>arr(n+5,{1e9,1e9});
    for(int i=0;i<n;i++)cin>>a[i],arr[i].F=a[i],arr[i].S=i;
    sort(arr.begin(),arr.end());
    int pos[n];
    for(int i=0;i<n;i++){
        pos[arr[i].S] = i;
    }
    function<int(int,int,int)> compute = [&](int x, int y, int k){
        int ans = 0;
        if(k<0)return ans;
        for(int i=0;i<n-1;i++){
            int c = k;
            if(pos[i]>c && pos[i+1]>c){
                ans = max(ans,min(2*arr[c].F,min(max(x,a[i]),max(y,a[i+1]))));
            }
            else if(pos[i]<c+2 && pos[i+1]<c+2){
                c = c+2;
                ans = max(ans,min(2*arr[c].F,min(max(x,a[i]),max(y,a[i+1]))));
            }
            else{
                c = c+1;
                ans = max(ans,min(2*arr[c].F,min(max(x,a[i]),max(y,a[i+1]))));
            }
        }
        return ans;
    };
    cout<<max({compute(0,0,k),compute(0,1e9,k-1),compute(1e9,0,k-1),compute(1e9,1e9,k-2)})<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}