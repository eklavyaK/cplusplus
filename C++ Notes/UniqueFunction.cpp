#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;

    vector<int> v(10);
    for(int i=0;i<10;i++){
        v[i]=rand()%5;
    }
    for(auto i : v) cout<<i<<' ';cout<<endl;
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto i : v) cout<<i<<' ';cout<<endl;
    sort(v.begin(),v.end());
    for(auto i : v) cout<<i<<' ';cout<<endl;
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto i : v) cout<<i<<' ';cout<<endl;
    return 0;
}