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
int a[8];
string c[8];
int ans=0;
bool solve(bool x){
    for(int i=0;i<8;i++){
        if(c[i][a[i]]=='*'){
            return false;
        }
    }
    for(int i=0;i<7;i++){
        for(int j=i+1;j<8;j++){
            if(j!=i && abs(a[j]-a[i])==j-i){
                return false;
            }
        }
    }
    return true;
}
int main(){
    rapid_iostream;
    for(int i=0;i<8;i++){
        cin>>c[i];
    }
    int n = 1;
    for(int i=2;i<9;i++){
        n*=i;
    }
    iota(a,a+8,0);
    for(int i=0;i<n;i++){
        ans+=solve(next_permutation(a,a+8));
    }
    cout<<ans<<endl;
    return 0;
}