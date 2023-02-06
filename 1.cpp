#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
const int mod = 998244353;
int exp(int a, int n){
    int ans = 1;
    while(n>0){
        if(n&1)ans = (ans*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return ans;
}
int mod_inv(int a){
    return exp(a,mod-2);
}
int compute(int n, int d){
    int f[d+1];
    f[0] = 0; f[1] = (exp(2,n)-1)%mod;;
    for(int i=2;i<=d;i++){
        int num = (n*((f[i-1]-1+mod)%mod)%mod-((i-1)*f[i-2])%mod+mod)%mod;
        int den = mod_inv(n-i+1);
        f[i] = (num*den)%mod;
    }
    return f[d];
}
void code(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    int diff = 0;
    for(int i=0;i<n;i++) if(s[i]!=t[i])diff++;
    cout<<compute(n,diff)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}