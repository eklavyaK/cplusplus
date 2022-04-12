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
vector<array<ll,3>> v;
ll n = 2000000000;
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    n=sqrt(n);for(int i = 3; i<=n; i+=2){
        ll a = i*i;
        ll b = (a-1)/2;
        ll c = (a+1)/2;
        ll k = c*c-b*b;
        if(k==a){
            k=sqrt(k);
            v.push_back({k,b,c});
        }
    }
    n=v.size();
    int tc;cin>>tc;while(tc--){
        int cnt = 0,k;cin>>k;
        for(int i = 0; i<n; i++){
            if(v[i][2]<=k){
                cnt++;
            }
            else break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}