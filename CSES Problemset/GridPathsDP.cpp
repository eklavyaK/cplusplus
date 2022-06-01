#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
int dp[1001][1001];
int main(){
    rapid_iostream;

    int n;cin>>n;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    if(s[0][0]!='*')dp[0][0]=1;
    else{print(0);return 0;}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]!='*'){
                if(i>0 && j>0){
                    dp[i][j]+=(dp[i][j-1]+dp[i-1][j])%mod1;
                }
                else if(i==0 && j>0){
                    dp[i][j]+=dp[i][j-1];
                }
                else if(i>0 && j==0){
                    dp[i][j]+=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}