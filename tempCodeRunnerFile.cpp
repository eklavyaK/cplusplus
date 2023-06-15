#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif

int mod = 1e9+7;

int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod; n>>=1;
    }
    return res;
}
void code(int TC){
    int n; cin>>n;
    string s; cin>>s;
    int cs = 0, c0 = 0, c4 = 0;
    int css[n]{}, c00[n]{}, c44[n]{};
    for(int i=0;i<n;i++){
        if(s[i]=='0') c0++;
        else if(s[i]=='*')cs++;
        else c4++;
        css[i] = cs;
        c00[i] = c0;
        c44[i] = c4;
    }
    int sum[n]{},suu[n]{};
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1];
        suu[i] = suu[i-1];
        if(s[i]=='*'){
            sum[i] += exp(2,cs-2)*css[i-1]+exp(2,cs-1)*c44[i-1];
            suu[i] += exp(2,cs-3)*css[i-1]+exp(2,cs-2)*c44[i-1];
        }
        else if(s[i]=='0'){
            sum[i] += exp(2,cs-1)*css[i-1]+exp(2,cs)*c44[i-1];
        }
        sum[i]%=mod;
        suu[i]%=mod;
    }
    int ans[n]{};
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1];
        if(s[i]=='4') ans[i] += sum[i-1];
        else if(s[i]=='*') ans[i] += sum[i-1]*exp(2,mod-2)%mod;
        debugarr(ans,n);
    }
    cout<<ans[n-1]%mod<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cerr.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}