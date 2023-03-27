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
    int l = 0, r = 1e9;
    function<bool(int)> go = [&](int c){
        if(c&1){
            c = (c+1)>>1;
            return 4*c*c>=n;
        }
        else{
            c>>=1;
            return 4*c*(c+1)+1>=n;
        }
    };
    while(l<=r){
        int mid = (l+r)>>1;
        if(go(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<r+1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}