#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

vector<pair<int,int>> s({{3,2},{3,1},{3,3},{2,2},{1,1},{2,1},{1,0},{2,0},{3,0}});
void code(){
    int n; cin>>n;
    int mx = 0;
    bool a = false, b = false;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx = max(mx,arr[i]/3);
        if(arr[i]%3==2) a = true;
        if(arr[i]%3==1) b = true;
    }
    function<bool(int,int)> check = [&](int a,int b){
        for(int i=0;i<n;i++){
            int k = min(arr[i]/3,mx-1)*3;
            int l = max(k-3,0ll);
            if(k+a!=arr[i]&&k+b!=arr[i]&&k+a+b!=arr[i]&&k!=arr[i]&&a!=arr[i]&&b!=arr[i]&&a+b!=arr[i]&&l+a!=arr[i]&&l+b!=arr[i]&&l+a+b!=arr[i]&&l!=arr[i]&&a!=arr[i]&&b!=arr[i]&&a+b!=arr[i]) return false;
        }
        return true;
    };
    int ans = mx+a+b, cnt = 0;
    if(a && b && mx){
        for(auto [a,b] : s) if(check(a,b)){
            cnt = max(cnt,1ll+(a==0||b==0));
        }
    }
    cout<<ans-cnt<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}