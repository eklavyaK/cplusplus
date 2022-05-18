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
    int n; cin>>n;
    vector<int> v;
    ll result = 1;
    for(int i = 1; i<=n; i++){
        if(gcd(n,i)==1){
            result=(result*i)%n;
            v.push_back(i);
        }
    }
    if(result==1){
        cout<<v.size()<<endl;
        for(auto i : v){
            cout<<i<<' ';
        }
    }
    else{
        cout<<v.size()-1<<endl;
        for(auto i : v){
            if(i!=result){
                cout<<i<<' ';
            }
        }
    }
    return 0;
}