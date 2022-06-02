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

int main(){
    rapid_iostream;

    int n;cin>>n;
    ll sum = 0;
    map<int,ll> m;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        sum+=k;
        m[sum%n]++;
    }
    ll ans = 0;
    for(auto [u,v] : m){
        ans+= (v*(v-1)/2+(u==0?v:0));
        if(m.count(u+n)){
            ans+=(v*m[u+n]);
        }
    }
    cout<<ans;
    return 0;
}