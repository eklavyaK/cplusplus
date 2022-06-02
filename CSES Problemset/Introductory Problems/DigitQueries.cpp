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
ll v[18];
int main(){
    rapid_iostream;
    string s = "10";v[1]=9;
    for(int i=2;i<18;i++){
        ll k = stoll(s);
        v[i]=v[i-1]+9*k*i;
        s+='0';
    }
    int q; cin>>q;
    while(q--){
        ll n; cin>>n;
        int in = lower_bound(v,v+18,n)-v;
        ll ans = pow(10,in-1)+ceil((ld)(n-v[in-1])/in)-1;
        ll r=(n-v[in-1])%in;r=r?r:in;
        string z = to_string(ans);
        cout<<z[r-1]<<endl;
    }
    return 0;
}