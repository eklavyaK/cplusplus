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
        ld tf=0, te=0, cf = 1, ce = 1,t=0;
        int n,l;cin>>n>>l;int a[n+2];a[0]=0;
        for(int i = 1; i<=n; i++)cin>>a[i];
        a[n+1]=l;vector<ld> f(n+2), e(n+2);
        for(int i = 1; i<=n+1; i++){
            tf+=(ld)(a[i]-a[i-1])/cf;
            f[i]=tf;cf++;
        }
        for(int i=n+1;i>=1;i--){
            te+=(ld)(a[i]-a[i-1])/ce;
            e[n+2-i]=te;ce++;
        }
        for(int i = 1; i<=n+1; i++){
            if(f[i]>=e[n+1-i]){
                int k = a[i]-a[i-1];
                ld ans = f[i-1]+((n+2-i)*(e[n+1-i]-f[i-1])+k)/(n+2);
                cout<<ans<<endl;break;
            }
        }
    }
    return 0;
}