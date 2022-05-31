#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl;
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n; int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int mx = a[0];int cnt = 0;
        for(int i=1;i<n;i++){
            if(a[i]<mx){
                cnt++;
                if(i+1<n){
                    mx=a[i+1];
                    i++;
                }
                else break;
            }
            else mx = max(mx,a[i]);
        }
        cout<<cnt<<endl;
    }
    return 0;
}