#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
ll cost = 1e15;
int a[200001];
int main(){
    rapid_iostream;
    int n; cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll x = a[0];
    ll f=0,e=0;
    for(int i=1;i<n;i++){
        e+=abs(a[i]-x);
    }
    cost=e;int j=0;
    while(j<n && a[j]==a[0])j++;
    for(;j<n;j++){
        f+=(a[j]-x)*j;
        e-=(a[j]-x)*(n-j);
        while(j+1<n && a[j]==a[j+1]){
            j++;
        }
        x=a[j];
        cost=min(cost,e+f);
    }
    cout<<cost<<endl;
    return 0;
}