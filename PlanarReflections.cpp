#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n,k; cin>>n>>k;
        long long dp[2][n+2];
        fill(dp[0],dp[0]+n+2,0);
        fill(dp[1],dp[1]+n+2,0);
        ll ans=1;if(k!=1)ans+=n;
        fill(dp[0]+1,dp[0]+n+1,1);
        for(int i=0;i<k-2;i++){
            if(i%2){
                for(int j=1;j<=n;j++){
                    dp[0][j]=(dp[0][j-1]+dp[1][j-1])%mod1;
                    ans=(ans+dp[0][j])%mod1;
                }
            }
            else{
                for(int j=n;j>=1;j--){
                    dp[1][j]=(dp[1][j+1]+dp[0][j+1])%mod1;
                    ans=(ans+dp[1][j])%mod1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}