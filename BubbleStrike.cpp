#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    ld n, p; cin>>n>>p;
    ld divisor = n*(n-1)*(n-2);
    function<bool(int)> check = [&](int x){
        ld a = x<3?0:x*(x-1)*(x-2);
        ld b = (x<2||n-x<1)?0:x*(x-1)*(n-x)*3;
        ld c = (n-x<2||x<1)?0:(n-x)*(n-x-1)*x*3/(ld)2;
        return (a+b+c)/divisor>=p;
    };
    int l = 0, r = n;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<r+1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}