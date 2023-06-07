#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int  mod = 998244353;
int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod; n>>=1;
    }
    return res;
}

void code(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    if(k==0){
        cout<<1<<endl;
        return;
    }
    int f[n+1]{1};
    for(int i=1;i<=n;i++) f[i] = (i*f[i-1])%mod;
    int ans = 0, cnt = 0, l = 0, r = -1;
    for(int i=0;i<n && l<n;i++){
        while(i<n){
            if(s[i]=='1') cnt++;
            if(cnt>k){
                cnt--; i--; break;
            }
            i++;
        }
        i = min(i,n-1);
        if(cnt==k) {
            ans = (ans + f[i-l+1]*exp(f[i-l+1-k],mod-2)%mod*exp(f[k],mod-2)%mod)%mod;
            if(l>0) ans = (ans - f[r-l+1]*exp(f[r-l+1-k+1],mod-2)%mod*exp(f[k-1],mod-2)%mod+mod)%mod;
            r = i;
        }
        while(l<n){
            if(s[l]=='1'){
                cnt--; l++; break;
            }
            l++;
        }
    }
    cout<<(r>=0?ans:1)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}