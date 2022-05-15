#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_io ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
ll a[20]={2,3,2,5,7,2,3,11,13,2,17,19,23,5,3,29,31,2,37,41};
ll g[20]={2,3,4,5,7,8,9,11,13,16,17,19,23,25,27,29,31,32,37,41};
vector<ll> f(20);
int main(){
    rapid_io;ll c = 1;
    for(int i = 0; i<20; i++){
        c*=a[i];f[i]=c;
    }
    int tc;cin>>tc;
    while(tc-->0){
        ll sum = 0;
        ll n; cin>>n; ll k = 0;
        for(int i=18;i>=0;i--){
            ll x = n/f[i];
            sum += (((x-k)*g[i+1])%mod1);
            sum = sum%mod1;
            k=x;
        }
        cout<<(sum+(n+n%2)%mod1)%mod1<<endl;
    }
    return 0;
}