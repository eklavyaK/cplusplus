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
    cout.precision(20);
    rapid_iostream;
    ll n,m; cin>>n>>m;
    ll a[n], b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a,a+n); ll g = 0;
    for(int i=1;i<n;i++){
        g = gcd(g,a[i]-a[i-1]);
    }
    for(int i=0;i<m;i++){
        cout<<gcd(g,b[i]+a[0])<<' ';
    }
    cout<<endl;
    return 0;
}