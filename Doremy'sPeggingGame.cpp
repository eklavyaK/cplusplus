#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int mod=1e9+7;
int fact[5005];
int f[2505][2505];
void binomialCoefficients(){
    for(int i=0;i<=2500;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i)f[i][j]=1;
            else f[i][j] = (f[i-1][j-1]+f[i-1][j])%mod;
        }
    }
}
void factorial(){
    fact[0]=1;
    for(int i=1;i<=5000;i++)fact[i] = (fact[i-1]*i)%mod;
}
void code(){
    int n; 
    cin>>n>>mod;
    factorial();
    binomialCoefficients();
    int k = (n-(n&1))>>1;
    int r = k-1, ans = 0;
    for(int i=0;i<k;i++,r++){
        int p = max(0ll,n-3-r);
        for(int j=0;j<=p;j++){
            ans = (ans+(f[p][j]*fact[r+j])%mod*(k-i))%mod;
        }
    }
    cout<<ans*n%mod<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}