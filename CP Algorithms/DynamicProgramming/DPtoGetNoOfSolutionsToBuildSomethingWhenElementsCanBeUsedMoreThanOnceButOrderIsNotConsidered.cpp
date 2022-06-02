#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define least int,vector<int>,greater<int>
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
const int M=1e6+5;
ll ans[M];
vector<map<int,short>> check(M);
int main(){
    rapid_iostream;
 
    int n; cin>>n;
    int x; cin>>x;
    ans[0]=1;int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=c[i];j<=x;j++){
            ans[j]=(ans[j]+ans[j-c[i]])%mod1;
        }
    }
    print(ans[x]);
    return 0;
}