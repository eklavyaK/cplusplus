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
int main(){
    rapid_iostream;
 
    int n; cin>>n;
    int x; cin>>x;
    ans[0]=1;int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<bool> v(x+1);
    v[0]=true;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-c[j]>=0 && v[i-c[j]]){
                ans[i]=(ans[i]+ans[i-c[j]])%mod1;
                v[i]=true;
            }
        }
    }
    if(v[x])print(ans[x]);
    else print(0);
    return 0;
}