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
    int tc;cin>>tc;int d=0;
    while(tc-->0){
        int n; cin>>n; string s[n];
        int cnt=0, k=0;d++;
        for(int i = 0; i<n; i++)cin>>s[i];
        for(int i = 0; i<n; i++){
            int c=0;
            for(int j = 0; j<n; j++){
                if(s[j][(i+j)%n]=='1'){
                    c++;cnt++;
                }
            }
            k=max(c,k);
        }
        cout<<cnt+n-2*k<<endl;
    }
    return 0;
}