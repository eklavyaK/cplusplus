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
int ans[(int)1e6+5];
int main(){
    rapid_iostream;
    int n; cin>>n;
    int x; cin>>x;
    int c[n];
    ans[0]=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<bool> v(x+1);
    v[0]=true;
    for(int i=1;i<=x;i++){
        int k = 1e6;
        for(int j=0;j<n;j++){
            if(i-c[j]>=0 && v[i-c[j]]){
                k = min(ans[i-c[j]]+1,k);
                v[i]=true;
            }
        }
        if(v[i])ans[i]=k;
    }
    if(v[x])print(ans[x]);
    else print(-1);
    return 0;
}