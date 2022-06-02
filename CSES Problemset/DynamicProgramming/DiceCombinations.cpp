#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define least int,vector<int>,greater<int>
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
const int M=1e6+5;
ll ans[M];
int main(){
    rapid_iostream;

    int n; cin>>n;
    ans[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                ans[i]=(ans[i]+ans[i-j])%mod1;
            }
            else break;
        }
    }
    cout<<ans[n];
    return 0;
}