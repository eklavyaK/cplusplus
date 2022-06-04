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
        int n; cin>>n;
        int a[n];
        int z = 1e9;
        int t=0,c=0,f=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            if(a[i]%2){
                f=1;
            }
            else{
                if(a[i]%4!=0)t++;
                else{
                    c++;
                    int m=a[i];
                    int k = 0;
                    while(m%4==0){
                        m/=2;
                        k++;
                    }
                    if(m%2==0)k++;
                    z = min(k,z);
                }
            }
        }
        if(f){
            cout<<c+t<<endl;
        }
        else if(t && c){
            cout<<t+c<<endl;
        }
        else if(t){
            cout<<t<<endl;
        }
        else{
            cout<<c+z-1<<endl;
        }
    }
    return 0;
}