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
    ll n,q; cin>>n>>q; ll a[n];
    ll sum = 0;
    ll u = 0;
    map<ll,ll> m;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
        m[i+1]=a[i];
    }
    while(q--){
        ll r; cin>>r;
        if(r==1){
            ll i,x;
            cin>>i>>x;
            if(m.count(i)){
                sum+=(x-m[i]);
                m[i]=x;
                cout<<sum<<endl;
            }
            else{
                sum+=(x-u);
                m[i]=x;
                cout<<sum<<endl;
            }
        }
        else{
            ll x;cin>>x;
            m.clear();
            sum=x*n;
            u=x;
            cout<<sum<<endl;
        }
    }
    return 0;
}