#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int n; cin>>n;
    ll result = 1l;
    for(int i = 2; i<=n; i++){
        result=(result*i)%mod1;
    }
    ll p = 1;
    for(int i = 1; i<n; i++){
        p=(p*2)%mod1;
    }
    if(result>p)cout<<result-p<<endl;
    else cout<<mod1+result-p<<endl;
}