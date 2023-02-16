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
    int n,k; cin>>n>>k;
    if(k>=n){
        cout<<exp(2,n)<<endl;
    }
    else{
        cout<<(exp(2,n)-exp(2,n-k)+1+2*mod)%mod<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}