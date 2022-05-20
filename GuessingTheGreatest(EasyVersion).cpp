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
int k;
void solve(int l, int r){
    int ans = l;
    while(l<=r){
        int mid = (l+r)/2;
        if(k>mid)
        cout<<'?'<<' '<<mid<<' '<<k<<endl<<flush;
        else
        cout<<'?'<<' '<<k<<' '<<mid<<endl<<flush;
        int x; cin>>x;
        if(x==k){
            ans=mid;
            if(mid<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        else{
            if(mid<k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    cout<<'!'<<' '<<ans<<endl;
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    int l = 1, r = n;
    cout<<'?'<<' '<<l<<' '<<r<<endl<<flush;
    cin>>k;
    if(r-l==1){
        cout<<'!'<<' '<<(k==l?r:l)<<endl;
        exit(0);
    }
    if(l==k){
        solve(2,n);
    }
    else if(k==n){
        solve(1,n-1);
    }
    else{
        cout<<'?'<<' '<<l<<' '<<k<<endl<<flush;
        int x; cin>>x;
        if(x==k){
            solve(l,k-1);
        }
        else{
            solve(k+1,r);
        }
    }
    return 0;
}