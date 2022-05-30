#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
int a[200001];
ll n,t;
bool check(ll x){
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum+=(x/a[i]);
    }
    return sum>=t;
}
int main(){
    rapid_iostream;

    cin>>n>>t;
    for(int i=0;i<n;i++)cin>>a[i];
    ll l = 1, r = (*min_element(a,a+n))*t;
    while(l<=r){
        ll mid = (l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<r+1<<endl;
    return 0;
}