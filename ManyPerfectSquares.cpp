#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> check(int n){
    vector<int> ret;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            int x = i, y = n/i;
            if((x+y)%2==0)ret.push_back((x+y)/2);
        }
    }
    return ret;
}
void code(){
    int n; cin>>n;
    int arr[n], ans = 1;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            vector<int> f = check(arr[j]-arr[i]);
            for(auto x : f){
                x = x*x-arr[j];
                if(x<0)continue;
                int cnt = 0;
                for(int k=0;k<n;k++){
                    int t = sqrt(arr[k]+x);
                    if(t*t==arr[k]+x)cnt++;
                }
                ans = max(ans,cnt);
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}