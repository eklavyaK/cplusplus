#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pii pair<int,int>
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
const int M = 1e6+5;
int dp[M];
int main(){
    rapid_iostream;
    int n,x; cin>>n>>x;
    int c[n],p[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        if(c[i]>x)continue;
        for(int j=x;j>0;j--){
            if(j-c[i]>=0){
                dp[j]=max(dp[j],dp[j-c[i]]+p[i]);
            }
        }
    }
    cout<<*max_element(dp,dp+x+1);
    return 0;
}