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
int n,k; 
int a[200001];
bool check(ll x){
    int cnt = 1;
    ll curr_sum=0;
    if(*max_element(a,a+n)>x)
        return false;
    for(int i=0;i<n;i++){
        if(curr_sum+a[i]>x){
            cnt++;
            curr_sum=a[i];
        }
        else curr_sum+=a[i];
    }
    return cnt<=k;
}
int main(){
    rapid_iostream;

    cin>>n>>k;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll l = 1, r = sum;
    while(l<=r){
        ll mid = (l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<r+1<<endl;

    return 0;
}