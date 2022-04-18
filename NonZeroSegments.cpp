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
    int n; cin>>n; int a[n],c=0,k=0;
    for(int i = 0; i<n; i++)cin>>a[i];
    map<ll,int> m; m[a[0]]=1;
    ll sum[n];sum[0]=a[0];m[0]=0;
    for(int i = 1; i<n; i++){
        sum[i]=a[i]+sum[i-1];
        if(m.count(sum[i])){
            if(m[sum[i]]>=k-1){
                c++;k=i+1;
            }m[sum[i]]=i+1;
        }
        else m[sum[i]]=i+1;
    }
    cout<<c<<endl;
    return 0;
}