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
    int tc;cin>>tc;
    while(tc-->0){
        ll c=0, d=0;
        ll n; cin>>n;
        if(n%2|| n==2){
            cout<<-1<<endl;
            continue;
        }
        ll k = n, cnt = 0;
        while(k%6!=0 && k>0){
            k-=4;cnt++;
        }
        c = k/6+cnt;
        cout<<c<<' ';
        cnt = 0;
        while(n%4!=0 && n>0){
            n-=6; cnt++;
        }
        cout<<n/4+cnt<<endl;
    }
    return 0;
}