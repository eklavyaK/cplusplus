#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int q,n; cin>>n>>q; int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        sort(a,a+n,greater<int>());
        ll sum[n];sum[0]=a[0];
        for(int i = 1; i<n; i++){
            sum[i]=sum[i-1]+a[i];
        }
        while(q--){
            ll x; cin>>x;
            int k = lower_bound(sum,sum+n,x)-sum;
            if(k==n){
                cout<<-1<<endl;
            }
            else cout<<k+1<<endl;
        }
    }
    return 0;
}