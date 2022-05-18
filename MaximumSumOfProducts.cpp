#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
ll a[5000+1],b[5000+1];
ll  result[5000+1];
int main(){
    rapid_iostream;
    int n; cin>>n; 
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    for(int i = 1; i<=n; i++){
        cin>>b[i];
    }
    ll sum = 0, ans=0;
    for(int i = 1; i<=n; i++){
        sum+=a[i]*b[i];
        result[i]=sum;
    }
    for(int i = 2; i<n; i++){
        ll x = a[i]*b[i];
        for(int j = 1; j<=min(i-1,n-i); j++){
            x+=(a[i-j]*b[i+j]+a[i+j]*b[i-j]);
            ans=max(sum+x-result[i+j]+result[i-j-1],ans);
        }
    }
    for(float i = 1.5; i<n; i+=1){
        ll x = 0;
        for(float j = 0.5; j<=min(i-1,n-i); j+=1){
            int l = i-j, r = i+j;
            x+=(a[l]*b[r]+a[r]*b[l]);
            ans=max(sum+x-result[r]+result[l-1],ans);
        }
    }
    cout<<max(ans,sum)<<endl;
    return 0;
}