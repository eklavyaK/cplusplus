#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl;
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int n,m; cin>>n>>m;
    set<int> a,b;int k;
    int rep_a=0,rep_b=0;
    for(int i=0;i<n;i++){
        cin>>k;
        a.insert(k);
    }
    for(int j=0;j<m;j++){
        cin>>k;
        b.insert(k);
    }
    for(auto i : a){
        rep_a+=(1<<(i+1));
    }
    for(auto i : b){
        rep_b+=(1<<(i+1));
    }
    int uni=rep_a|rep_b, intr=rep_a&rep_b;
    cout<<"Size of the intersection is: "<<__builtin_popcount(intr)<<endl;
    cout<<"Size of the union is: "<<__builtin_popcount(uni)<<endl;
    for(int i=0;i<32;i++){
        if(uni&(1<<i)){
            cout<<i-1<<' ';
        }
    }
    cout<<'\n';
    for(int i=0;i<32;i++){
        if(intr&(1<<i)){
            cout<<i-1<<' ';
        }
    }
    cout<<'\n';
    return 0;
}