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
void print(int x){
    cout<<'!'<<' '<<x<<endl; exit(0);
}
int main(){
    rapid_iostream;
    int n,t; cin>>n>>t;
    int k,ans; cin>>k;
    int l = 1, r=n;
    while(l<=r){
        int mid = (l+r)/2;int c;
        cout<<'?'<<' '<<1<<' '<<mid<<endl<<flush;
        cin>>c;
        if(mid-k==c){
            r=mid-1;
            ans=mid;
        }
        else if(mid-k>c){
            r=mid-1;
        }
        else l=mid+1;
    }
    print(ans);
    return 0;
}