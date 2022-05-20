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
    int tc;cin>>tc;
    while(tc-->0){
        int n,k; cin>>n>>k;
        for(int i=0;i<k-3;i++){
            cout<<1<<' ';
        }
        n-=(k-3);
        if(n%2)cout<<1<<' '<<n/2<<' '<<n/2<<endl;
        else if((n/2)%2==0)
        cout<<n/4<<' '<<n/4<<' '<<n/2<<endl;
        else cout<<2<<' '<<n/2-1<<' '<<n/2-1<<endl;
    }
    return 0;
}