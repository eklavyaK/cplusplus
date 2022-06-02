#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#include<bits/stdc++.h>
#define F first 
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define binary(n,k) bitset<k>(n).to_string()
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;

    int n; cin>>n;
    vector<pair<int,int>> v;
    v.push_back({0,0});
    int x = 0;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        while(v[x].F>=k){
            v.pop_back();
            x--;
        }
        cout<<v[x].S<<' ';
        v.push_back({k,i+1});
        x++;
    }

    return 0;
}