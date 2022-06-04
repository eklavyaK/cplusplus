#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pii pair<int,int>
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
    int tc;cin>>tc;
    while(tc-->0){
        ll n,k;cin>>n>>k;
        int a[n];ll sum[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sum[0]=a[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        ll result = 0;
        if(k>=n){
            result = sum[n-1]+k*n-n*(n+1)/2;
        }
        else
        {result = sum[k-1];
        for(int i=k;i<n;i++){
            result=max(result,sum[i]-sum[i-k]);
        }
        result += k*(k-1)/2;}
        cout<<result<<endl;
    }
    return 0;
}