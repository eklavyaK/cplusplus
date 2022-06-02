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
    int n,k; cin>>n;
    ll x; cin>>x;
    ll a[n+1];a[0]=0;
    map<ll,ll> m;
    for(int i=1;i<=n;i++){
        cin>>k;
        a[i]=a[i-1]+k;
        m[a[i]]++;
    }
    ll cnt = 0;
    if(x==0){
        if(m.count(0)){
            cnt+=m[0];
        }
        for(auto i : m){
            cnt+=(i.second*(i.second-1))/2;
        }
    }
    else{
        if(m.count(x)){
            cnt+=m[x];
        }
        for(int i=1;i<=n;i++){
            if(m[a[i]+x]){
                cnt+=m[a[i]+x];
            }
            m[a[i]]--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}