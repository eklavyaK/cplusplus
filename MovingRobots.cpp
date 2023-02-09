#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int mod = 1e9+7;

int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return res;
}

void code(){
    int n; cin>>n;
    vector<int> arr(n);
    map<int,int> m;
    for(int i=0;i<n;i++)cin>>arr[i], m[arr[i]]=i;
    int ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int diff = arr[j]-arr[i];
            int k = 1, l = 1;
            auto it = lower_bound(arr.begin(),arr.end(),arr[j]+diff);
            if(it!=arr.end()){
                k = exp(2,n-m[*it]);
            }
            it = lower_bound(arr.begin(),arr.end(),arr[i]-diff);
            if(it!=arr.begin()){
                it--;
                l = exp(2,m[*it]+1)%mod;
            }
            ans = (ans + k*l)%mod;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}